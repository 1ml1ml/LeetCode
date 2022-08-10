#pragma once

#include <vector>
#include <string>

class CSolution 
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) 
	{
		std::string nRet;
		for (int nI = 0; true; nRet.push_back(strs[0][nI++]))
			for (int nJ = 0; nJ < strs.size(); nJ++)
				if (nI >= strs[nJ].size() || strs[0][nI] != strs[nJ][nI])
					return nRet;
		return nRet;
	}
};
