#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <stdexcept>
# include <algorithm>
# include <string>
# include <sys/time.h>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseArguments(int argc, char** argv);

        void sortVector();
        void sortDeque();

        void printBefore() const;
        void printAfter() const;
        void printTimeVector() const;
        void printTimeDeque() const;

    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;
        double           _vectorTime;
        double           _dequeTime;

        std::vector<int> mergeInsertSortVector(std::vector<int> ids,
                                                std::vector<int>& values);
        void insertSortedVector(std::vector<int>& mainChain, int id,
                                 std::vector<int>& values, size_t rangeEnd);
        std::deque<int> mergeInsertSortDeque(std::deque<int> ids,
                                              std::deque<int>& values);
        void insertSortedDeque(std::deque<int>& mainChain, int id,
                                std::deque<int>& values, size_t rangeEnd);

        static double elapsedMicro(const struct timeval& start, const struct timeval& end);
};

#endif
