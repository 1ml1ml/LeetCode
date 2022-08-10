#pragma once

#include <iostream>
#include <string>

class CSolution 
{
public:
    std::string countAndSay(int n) 
    {
        if (1 == n)
            return "1";

        std::string str = countAndSay(n - 1), strRet;
        for (int i = 0, size = str.size(); i < size; i++)
        {
            int count = 1;
            while (i + 1 < size && str[i] == str[i + 1])
                i++, count++;
            strRet += std::to_string(count) + str[i];
        }
        return strRet;
    }
};
