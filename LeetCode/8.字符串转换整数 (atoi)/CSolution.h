#pragma once

#include <iostream>

class CSolution
{
public:
	int myAtoi(std::string s)
	{
		int nRet = 0, nFlag = 0;	//正负标志位
		for (auto itrBegin = s.begin(), itrEnd = s.end(); itrBegin != itrEnd; itrBegin++)
		{
			//确定正负号
			if (0 == nFlag)
			{
				if (*itrBegin == ' ')
					continue;

				if (*itrBegin == '+')
				{
					nFlag = 1;
					continue;
				}

				if (*itrBegin == '-')
				{
					nFlag = -1;
					continue;
				}

				//如果不是空格,+,-则字符串不合法
				if (*itrBegin < '0' || *itrBegin > '9')
					return 0;

				//标志位默认为正
				nFlag |= 1;
			}

			if (*itrBegin >= '0' && *itrBegin <= '9')
			{
				//溢出判断
				if ((INT_MAX / 10 == nRet && *itrBegin - '0' > INT_MAX % 10) || nRet > INT_MAX / 10)
					return INT_MAX;

				//溢出判断
				if ((INT_MIN / 10 == nRet && -(*itrBegin - '0') < INT_MIN % 10) || nRet < INT_MIN / 10)
					return INT_MIN;

				nRet = nRet * 10 + nFlag * (*itrBegin - '0');
			}
			//不是数字则转换结束
			else break;
		}
		return nRet;
	}
};

