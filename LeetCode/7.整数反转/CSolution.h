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
			//Òç³öÅÐ¶Ï
			if (nRet > INT_MAX / 10 || nRet < INT_MIN / 10)
				return 0;

			//·´×ª
			nRet = nRet * 10 + x % 10;
			x /= 10;
		}
		return nRet;
	}
};

