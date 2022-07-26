#pragma once

#include <vector>
#include <string>
#include <set>
#include <iostream>

class CSolution 
{
public:
    std::vector<std::string> generateParenthesis(int n) 
    {
        recursion("", n, 0, 0);
        return m_vecRet;
    }

private:
    void recursion(const std::string& strBase, int n, int nLeft, int nRight)
    {
        if (strBase.size() == 2 * n)
            m_vecRet.push_back(strBase);
        else
        {
            //用n来限制(的数量
            if (nLeft < n)
                recursion(strBase + '(', n, nLeft + 1, nRight);
            //用(的数量来限制)的数量
            if (nRight < nLeft)
                recursion(strBase + ')', n, nLeft, nRight + 1);
        }
    }

private:
    std::vector<std::string> m_vecRet;
};
