#pragma once

#include <vector>
#include <algorithm>

class CSolution {
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
		//排序
        std::sort(nums.begin(), nums.end());

		int nRet = INT_MAX, nDIFF = INT_MAX;
        for (int nI = 0, nSize = nums.size(); nI < nSize; nI++)
        {
			//过滤重复值
            if (0 == nI || nums[nI] != nums[nI - 1])
            {
				int nJ = nI + 1, nK = nSize - 1;
				while (nK > nJ)
				{
					int&& nSum = nums[nI] + nums[nJ] + nums[nK];
					if (nSum == target)
						return target;

					int&& nSumDIFF = abs(nSum - target);
					if (INT_MAX == nRet || nSumDIFF < nDIFF)
					{
						//替换成新的最接近的值
						nRet = nSum;
						nDIFF = nSumDIFF;
					}

					if (nSum > target)
					{
						//对于有序的nums,三数和大于目标值,将大值nK减小
						do nK--;
						//过滤重复值
						while (nK > nJ && nums[nK - 1] == nums[nK]);
					}
					else if (nSum < target)
					{
						//对于有序的nums,三数和小于目标值,将小值nJ增大
						do nJ++;
						//过滤重复值
						while (nK > nJ && nums[nJ + 1] == nums[nJ]);
					}
				}
            }
        }
        return nRet;
    }
};