#pragma once

#include <iostream>
#include <string>
#include <vector>

#if 1

//自己写的方法多次优化后 /(ㄒoㄒ)/~~
class CSolution
{
public:
    std::string convert(std::string s, int numRows)
    {
        //一行或者一列直接返回s
        if (numRows == 1 || numRows >= s.size())
            return s;

        std::vector<std::string> vec(numRows, std::string());
        for (int nI = 0, nSize = s.size(), nX = 0; nI < nSize; )
        {
            //画竖列 每次都是从0到numRows-1行
            for (nX = 0; nX < numRows && nI < nSize; nX++)
                vec[nX] += s[nI++];

            //画斜列 每次都是从numRow-2到1行开始
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

//压缩矩阵方法 大佬牛皮
class CSolution 
{
public:
    std::string convert(std::string s, int numRows)
    {
        //一行或者一列直接返回s
        if (numRows == 1 || numRows >= s.size())
            return s;

        std::vector<std::string> vec(numRows, std::string());

        //nT循环周期 每一个周期要添加2 * numRows - 2个字符
        for (int nI = 0, nX = 0, nT = 2 * numRows - 2; nI < s.size(); nI++)
        {
            //每一次添加的字符总是在该行的末尾
            vec[nX] += s[nI];

            //nI % nT < numRows - 1 
            //成立 表明此时添加的字符应该在竖列所以nX向下走
            //不成立 表明此时添加的字符应该在斜列所以nX往上走
            nI % nT < numRows - 1 ? nX++ : nX--;
        }

        //每行相加获得结果
        std::string strRet;
        for (std::string& str : vec)
            strRet += str;

        return strRet;
    }
};

#endif