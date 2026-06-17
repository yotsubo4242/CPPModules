#include "PmergeMe.hpp"

// testスクリプト: bash -c 'ARGS=$(shuf -r -i 1-1000 -n 3000 | tr "\n" " "); ./PmergeMe $ARGS' > result.txt

int main(int argc, char** argv)
{
    PmergeMe pmerge;

    try
    {
        pmerge.parseArguments(argc, argv);
        pmerge.printBefore();
        pmerge.sortVector();
        pmerge.sortDeque();
        pmerge.printAfter();
        pmerge.printTimeVector();
        pmerge.printTimeDeque();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
