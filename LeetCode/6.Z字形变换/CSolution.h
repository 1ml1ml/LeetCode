#pragma once

#include <iostream>
#include <string>
#include <vector>

#if 1

//�Լ�д�ķ�������Ż��� /(��o��)/~~
class CSolution
{
public:
    std::string convert(std::string s, int numRows)
    {
        //һ�л���һ��ֱ�ӷ���s
        if (numRows == 1 || numRows >= s.size())
            return s;

        std::vector<std::string> vec(numRows, std::string());
        for (int nI = 0, nSize = s.size(), nX = 0; nI < nSize; )
        {
            //������ ÿ�ζ��Ǵ�0��numRows-1��
            for (nX = 0; nX < numRows && nI < nSize; nX++)
                vec[nX] += s[nI++];

            //��б�� ÿ�ζ��Ǵ�numRow-2��1�п�ʼ
            for (nX = numRows - 2; nX >= 1 && nI < nSize; nX--)
                vec[nX] += s[nI++];
        }

        std::string strRet;
        for (std::string& str : vec)
            strRet += str;

        return strRet;
    }
};

#else

//ѹ�����󷽷� ����ţƤ
class CSolution 
{
public:
    std::string convert(std::string s, int numRows)
    {
        //һ�л���һ��ֱ�ӷ���s
        if (numRows == 1 || numRows >= s.size())
            return s;

        std::vector<std::string> vec(numRows, std::string());

        //nTѭ������ ÿһ������Ҫ���2 * numRows - 2���ַ�
        for (int nI = 0, nX = 0, nT = 2 * numRows - 2; nI < s.size(); nI++)
        {
            //ÿһ����ӵ��ַ������ڸ��е�ĩβ
            vec[nX] += s[nI];

            //nI % nT < numRows - 1 
            //���� ������ʱ��ӵ��ַ�Ӧ������������nX������
            //������ ������ʱ��ӵ��ַ�Ӧ����б������nX������
            nI % nT < numRows - 1 ? nX++ : nX--;
        }

        //ÿ����ӻ�ý��
        std::string strRet;
        for (std::string& str : vec)
            strRet += str;

        return strRet;
    }
};

#endif