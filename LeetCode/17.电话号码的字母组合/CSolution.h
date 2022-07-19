#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

class CSolution 
{
public:
    std::vector<std::string> letterCombinations(std::string digits) 
    {
        m_nMaxSize = digits.size();
        if(0 != m_nMaxSize)
			recursion("", digits.begin());
        return m_vecRet;
    }

    void recursion(const std::string& strCur, decltype(std::string().begin()) itrBegin)
    {
        if (strCur.size() >= m_nMaxSize)
            m_vecRet.push_back(strCur);
        else
            for(auto& c : m_map[*itrBegin])
                recursion(strCur + c, itrBegin + 1);
    }

private:
    int m_nMaxSize = 0;
    std::vector<std::string> m_vecRet;
    std::map<char, std::string> m_map = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
};
