#pragma once

#include <string>
#include <vector>

class CSolution
{
public:
	std::string intToRoman(int nNum)
	{
		std::string strRet;
		for (int nI = 1, nTemp; nNum > 0; nI++)
		{
			const std::pair<char, char>& pairRoman = sm_vecPairRoman[nI - 1];

			nTemp = nNum % static_cast<int>(pow(10, nI));
			nNum -= nTemp;

			if ((nTemp /= static_cast<int>(pow(10, nI - 1))) < 5)
				4 == nTemp ? strRet.insert(0, { pairRoman.first, pairRoman.second }) : strRet.insert(0, nTemp, pairRoman.first);
			else if (5 == nTemp)
				strRet.insert(0, 1, pairRoman.second);
			else if (nTemp > 5)
				9 == nTemp ? strRet.insert(0, { pairRoman.first, sm_vecPairRoman[nI].first }) : strRet.insert(0, std::string(nTemp - 5, pairRoman.first).insert(0, 1, pairRoman.second));
		}
		return strRet;
	}

private:
	static std::vector<std::pair<char, char>> sm_vecPairRoman;
};

std::vector<std::pair<char, char>> CSolution::sm_vecPairRoman = { std::pair<char, char>('I', 'V'), std::pair<char, char>('X', 'L'), std::pair<char, char>('C', 'D'), std::pair<char, char>('M', 'M') };
