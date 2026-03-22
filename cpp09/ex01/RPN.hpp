#ifndef RPN_HPP
#define RPN_HPP


# include <stack>
# include <list>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cctype>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int evaluate(const std::string &expression);

    private:
        std::stack<int, std::list<int> > stack;

        bool isOperator(const std::string &token);
        int  apply(int a, int b, char op);
};



#endif