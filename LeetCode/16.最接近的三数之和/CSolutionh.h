#pragma once

#include <vector>
#include <algorithm>

class CSolution {
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
		//����
        std::sort(nums.begin(), nums.end());

		int nRet = INT_MAX, nDIFF = INT_MAX;
        for (int nI = 0, nSize = nums.size(); nI < nSize; nI++)
        {
			//�����ظ�ֵ
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
						//�滻���µ���ӽ���ֵ
						nRet = nSum;
						nDIFF = nSumDIFF;
					}

					if (nSum > target)
					{
						//���������nums,�����ʹ���Ŀ��ֵ,����ֵnK��С
						do nK--;
						//�����ظ�ֵ
						while (nK > nJ && nums[nK - 1] == nums[nK]);
					}
					else if (nSum < target)
					{
						//���������nums,������С��Ŀ��ֵ,��СֵnJ����
						do nJ++;
						//�����ظ�ֵ
						while (nK > nJ && nums[nJ + 1] == nums[nJ]);
					}
				}
            }
        }
        return nRet;
    }
};