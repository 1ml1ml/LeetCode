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
        std::vector<int> vecNext = getNext(needle);
        int i = 0, j = 0;
        while (i < haystack.size() && j < static_cast<int>(needle.size()))
        {
            if (-1 == j || haystack[i] == needle[j])
                i++, j++;
            else j = vecNext[j];
        }
        return j == needle.size() ? i - j : -1;
    }

private:
    std::vector<int> getNext(const std::string& str)
    {
        std::vector<int> vecNext(str.size(), -1);
        for (int i = 0, j = -1; i < str.size() - 1; )
        {
            if (-1 == j || str[i] == str[j])
            {
                if (str[++i] == str[++j])
                    vecNext[i] = vecNext[j];
                else vecNext[i] = j;
            }
            else j = vecNext[j];
        }
        return vecNext;
    }
};
