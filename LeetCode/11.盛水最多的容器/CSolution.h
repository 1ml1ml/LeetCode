#pragma once

#include <vector>

class Solution
{
public:
	int maxArea(std::vector<int>& height)
	{
		int nRet = 0;
		for (int nLeft = 0, nRight = height.size() - 1, nWidth = 0, nArea = 0; nLeft < nRight; )
		{
			nWidth = nRight - nLeft;
			nArea = nWidth * (height[nLeft] < height[nRight] ? height[nLeft++] : height[nRight--]);

			if (nArea > nRet)
				nRet = nArea;
		}
		return nRet;
	}
};
