#pragma once

#include <iostream>

class CSolution
{
public:
	int reverse(int x)
	{
		int nRet = 0;
		while (x != 0)
		{
			//溢出判断
			if (nRet > INT_MAX / 10 || nRet < INT_MIN / 10)
				return 0;

			//反转
			nRet = nRet * 10 + x % 10;
			x /= 10;
		}
		return nRet;
	}
};

