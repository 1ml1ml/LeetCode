#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include <set>

class CSolution 
{
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& vecNum)
	{
		//排序
		std::sort(vecNum.begin(), vecNum.end());

		std::vector<std::vector<int>> vecRet;
		for (int nI = 0, nSize = vecNum.size(); nI < nSize; nI++)
		{
			//过滤掉重复值
			if (0 == nI || vecNum[nI] != vecNum[nI - 1])
			{
				for (int nLeft = nI + 1, nRight = nSize - 1, nTarget = -vecNum[nI]; nLeft < nRight; nLeft++)
				{
					//过滤掉重复值
					if (nI + 1 == nLeft || vecNum[nLeft] != vecNum[nLeft - 1])
					{
						//找到<=target的两个下标
						while (nLeft < nRight && vecNum[nLeft] + vecNum[nRight] > nTarget)
							nRight--;

						//如果下标重合 随着left的增大 left和right的和也增大 不会再出现<=target的值 直接返回
						if (nLeft == nRight)
							break;

						if (vecNum[nLeft] + vecNum[nRight] == nTarget)
							vecRet.push_back({ vecNum[nI], vecNum[nLeft], vecNum[nRight] });
					}
				}
			}
		}
		return vecRet;
	}
};
