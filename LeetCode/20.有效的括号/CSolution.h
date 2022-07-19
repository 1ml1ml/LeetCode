#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class CSolution
{
public:
    bool isValid(std::string s)
    {
        if (s.size() % 2 != 0)
            return false;

        std::unordered_map<char, char> map = { {')', '('}, {'}', '{'}, {']', '['} };

        std::stack<char> stack;
        for (auto& c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                stack.push(c);
            else if (true == stack.empty() || map[c] != stack.top())
                return false;
            else stack.pop();
        }
        return stack.empty();
    }
};
