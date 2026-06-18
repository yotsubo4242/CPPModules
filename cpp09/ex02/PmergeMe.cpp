#include "PmergeMe.hpp"
#include <climits>
#include <cctype>
#include <cstdlib>

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArguments(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg.empty())
            throw std::runtime_error("Error");
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::runtime_error("Error");
        }

        char* end = NULL;
        long value = std::strtol(arg.c_str(), &end, 10);
        if (*end != '\0' || value <= 0 || value > INT_MAX)
            throw std::runtime_error("Error");

        _vec.push_back(static_cast<int>(value));
        _deq.push_back(static_cast<int>(value));
    }
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << (i + 1 < _vec.size() ? " " : "");
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _deq.size(); ++i)
        std::cout << _deq[i] << (i + 1 < _deq.size() ? " " : "");
    std::cout << std::endl;
}

void PmergeMe::printTimeVector() const
{
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << _vectorTime << " us" << std::endl;
}

void PmergeMe::printTimeDeque() const
{
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}

double PmergeMe::elapsedMicro(const struct timeval& start, const struct timeval& end)
{
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

/* ============================== vector ============================== */

void PmergeMe::sortVector()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    std::vector<int> ids;
    for (size_t i = 0; i < _vec.size(); ++i)
        ids.push_back(static_cast<int>(i));

    std::vector<int> sortedIds = mergeInsertSortVector(ids, _vec);

    std::vector<int> result;
    for (size_t i = 0; i < sortedIds.size(); ++i)
        result.push_back(_vec[sortedIds[i]]);
    _vec = result;

    gettimeofday(&end, NULL);
    _vectorTime = elapsedMicro(start, end);
}

void PmergeMe::insertSortedVector(std::vector<int>& mainChain, int id, std::vector<int>& values, size_t rangeEnd)
{
    int value = values[id];
    size_t lo = 0;
    size_t hi = rangeEnd;

    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (values[mainChain[mid]] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    mainChain.insert(mainChain.begin() + lo, id);
}

std::vector<int> PmergeMe::mergeInsertSortVector(std::vector<int> ids, std::vector<int>& values)
{
    if (ids.size() <= 1)
        return ids;

    std::vector<int> partner(values.size(), -1);

    bool hasOdd = (ids.size() % 2 != 0);
    int oddId = -1;
    if (hasOdd)
    {
        oddId = ids.back();
        ids.pop_back();
    }

    std::vector<int> largerIds;
    for (size_t i = 0; i < ids.size(); i += 2)
    {
        int idA = ids[i];
        int idB = ids[i + 1];
        int largerId, smallerId;
        if (values[idA] >= values[idB])
        {
            largerId = idA;
            smallerId = idB;
        }
        else
        {
            largerId = idB;
            smallerId = idA;
        }
        largerIds.push_back(largerId);
        partner[largerId] = smallerId;
    }

    std::vector<int> mainChain = mergeInsertSortVector(largerIds, values);

    int firstLargerId = mainChain.front();
    int a1 = partner[firstLargerId];
    mainChain.insert(mainChain.begin(), a1);

    std::vector<int> pendList;
    std::vector<int> boundList;
    for (size_t i = 2; i < mainChain.size(); ++i)
    {
        pendList.push_back(partner[mainChain[i]]);
        boundList.push_back(mainChain[i]);
    }
    if (hasOdd)
    {
        pendList.push_back(oddId);
        boundList.push_back(-1);
    }

    std::vector<size_t> bounds;
    bounds.push_back(0);
    bounds.push_back(1);
    while (bounds.back() < pendList.size())
    {
        size_t next = bounds[bounds.size() - 1] + 2 * bounds[bounds.size() - 2];
        bounds.push_back(next);
    }

    for (size_t k = 1; k < bounds.size(); ++k)
    {
        size_t lo = bounds[k - 1];
        if (lo >= pendList.size())
            break;
        size_t hi = std::min(bounds[k], pendList.size());

        for (size_t p = hi; p > lo; --p)
        {
            int pendId = pendList[p - 1];
            int boundId = boundList[p - 1];

            size_t rangeEnd;
            if (boundId == -1)
                rangeEnd = mainChain.size();
            else
            {
                std::vector<int>::iterator it = std::find(mainChain.begin(), mainChain.end(), boundId);
                rangeEnd = static_cast<size_t>(it - mainChain.begin());
            }
            insertSortedVector(mainChain, pendId, values, rangeEnd);
        }
    }

    return mainChain;
}

/* ============================== deque ============================== */

void PmergeMe::sortDeque()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    std::deque<int> ids;
    for (size_t i = 0; i < _deq.size(); ++i)
        ids.push_back(static_cast<int>(i));

    std::deque<int> sortedIds = mergeInsertSortDeque(ids, _deq);

    std::deque<int> result;
    for (size_t i = 0; i < sortedIds.size(); ++i)
        result.push_back(_deq[sortedIds[i]]);
    _deq = result;

    gettimeofday(&end, NULL);
    _dequeTime = elapsedMicro(start, end);
}

void PmergeMe::insertSortedDeque(std::deque<int>& mainChain, int id, std::deque<int>& values, size_t rangeEnd)
{
    int value = values[id];
    size_t lo = 0;
    size_t hi = rangeEnd;

    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (values[mainChain[mid]] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    mainChain.insert(mainChain.begin() + lo, id);
}

std::deque<int> PmergeMe::mergeInsertSortDeque(std::deque<int> ids, std::deque<int>& values)
{
    if (ids.size() <= 1)
        return ids;
    std::deque<int> partner(values.size(), -1);

    bool hasOdd = (ids.size() % 2 != 0);
    int oddId = -1;
    if (hasOdd)
    {
        oddId = ids.back();
        ids.pop_back();
    }

    std::deque<int> largerIds;
    for (size_t i = 0; i < ids.size(); i += 2)
    {
        int idA = ids[i];
        int idB = ids[i + 1];
        int largerId, smallerId;
        if (values[idA] >= values[idB])
        {
            largerId = idA;
            smallerId = idB;
        }
        else
        {
            largerId = idB;
            smallerId = idA;
        }
        largerIds.push_back(largerId);
        partner[largerId] = smallerId;
    }

    std::deque<int> mainChain = mergeInsertSortDeque(largerIds, values);

    int firstLargerId = mainChain.front();
    int a1 = partner[firstLargerId];
    mainChain.push_front(a1);

    // pendList: 挿入待ちidのリスト
    std::deque<int> pendList;
    // boundList: 挿入時の範囲上限のidのリスト
    std::deque<int> boundList;
    for (size_t i = 2; i < mainChain.size(); ++i)
    {
        pendList.push_back(partner[mainChain[i]]);
        boundList.push_back(mainChain[i]);
    }
    if (hasOdd)
    {
        pendList.push_back(oddId);
        boundList.push_back(-1);
    }

    // bounds: 挿入順序のリスト
    std::deque<size_t> bounds;
    bounds.push_back(0);
    bounds.push_back(1);
    while (bounds.back() < pendList.size())
    {
        size_t next = bounds[bounds.size() - 1] + 2 * bounds[bounds.size() - 2];
        bounds.push_back(next);
    }

    for (size_t k = 1; k < bounds.size(); ++k)
    {
        size_t lo = bounds[k - 1];
        if (lo >= pendList.size())
            break;
        size_t hi = std::min(bounds[k], pendList.size());

        for (size_t p = hi; p > lo; --p)
        {
            int pendId = pendList[p - 1];
            int boundId = boundList[p - 1];

            size_t rangeEnd;
            if (boundId == -1)
                rangeEnd = mainChain.size();
            else
            {
                std::deque<int>::iterator it = std::find(mainChain.begin(), mainChain.end(), boundId);
                rangeEnd = static_cast<size_t>(it - mainChain.begin());
            }
            insertSortedDeque(mainChain, pendId, values, rangeEnd);
        }
    }

    return mainChain;
}
