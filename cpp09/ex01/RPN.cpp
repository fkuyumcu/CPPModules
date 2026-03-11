#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &other) : stack(other.stack)
{

}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN()
{

}



bool RPN::isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}


int RPN::apply(int a, int b, char op)
{
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("division by zero");
        return a / b;
    }

    throw std::runtime_error("unknown operator");

}


int RPN::evaluate(const std::string &expression)
{
    while (!stack.empty())
        stack.pop();

    //input ss
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isOperator(token))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error");

            int b = stack.top(); stack.pop(); // last in
            int a = stack.top(); stack.pop(); // second to last in

            stack.push(apply(a, b, token[0]));
        }
        else
        {
            if (token.size() != 1 || !isdigit(token[0]))
                throw std::runtime_error("Error");

            stack.push(token[0] - '0');
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");

    return stack.top();
}