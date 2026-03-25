#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <ctime>
# include <cctype>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void    run(int argc, char **argv);

    private:
        std::vector<int> vec;
        std::deque<int>  deq;

        void    parseInput(int argc, char **argv);

        void    sortVector(std::vector<int> &v);
        void    insertVector(std::vector<int> &chain, int val, int limit);

        void    sortDeque(std::deque<int> &d);
        void    insertDeque(std::deque<int> &chain, int val, int limit);
};

#endif