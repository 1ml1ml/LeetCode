#pragma once

#include <iostream>

class CSolution
{
public:
    bool isPalindrome(int x)
    {
        if (x >= 0 && x < 10)
            return true;

        if (x < 0 || x % 10 == 0)
            return false;

        int nHalfReverse = __halfReverse(x);
        return nHalfReverse == x || nHalfReverse == (x * 10 + nHalfReverse % 10);
    }

private:
    inline int __halfReverse(int& x)
    {
        //反转一半数字
        int nHalfReverse = 0;
        while (x > nHalfReverse)
        {
            nHalfReverse = nHalfReverse * 10 + x % 10;
            x /= 10;
        }
        return nHalfReverse;
    }
};

