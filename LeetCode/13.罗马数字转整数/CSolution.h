#pragma once

#include <string>
#include <map>

class CSolution 
{
public:
	int romanToInt(std::string str)
	{
		int nRet = 0;
		for (int nI = str.size() - 1; nI >= 0; nI--)
			sm_mapInt[str[nI]] < sm_mapInt[str[nI + 1]] ? nRet -= sm_mapInt[str[nI]] : nRet += sm_mapInt[str[nI]];
		return nRet;
	}

private:
	static std::map<char, int> sm_mapInt;
};

std::map<char, int> CSolution::sm_mapInt{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
