#pragma once

#include <iostream>
#include <string>
#include <vector>

class CSolution
{
public:
    //KMPÀ„∑®
    int strStr(const std::string& haystack, const std::string& needle)
    {
        if (0 == needle.size())
            return 0;

        std::vector<int> vecNext = getNext(needle);
        for (int i = 0, j = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = vecNext[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size())
                return i - j + 1;
        }
        return -1;
    }

private:
    std::vector<int> getNext(const std::string& str)
    {
        std::vector<int> vecNext(str.size());
        for (int i = 1, j = 0; i < str.size(); i++)
        {
            while (j > 0 && str[i] != str[j])
                j = vecNext[j - 1];
            if (str[i] == str[j])
                j++;
            vecNext[i] = j;
        }
        return vecNext;
    }
};
