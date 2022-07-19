#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class CSolution 
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> vecRet;
        for (int nA = 0, nSize = nums.size(); nA < nSize; nA++)
        {
            if (0 == nA || nums[nA] != nums[nA - 1])
            {
                for (int nB = nA + 1; nB < nSize; nB++)
                {
                    if (nA + 1 == nB || nums[nB] != nums[nB - 1])
                    {
                        for (int nC = nB + 1, nD = nSize - 1; nC < nD; nC++)
                        {
                            if (nB + 1 == nC || nums[nC] != nums[nC - 1])
                            {
                                long long nTemp = 0;

                                do nTemp = (long long)nums[nA] + nums[nB] + nums[nC] + nums[nD--];
                                while (nC < nD && nTemp > target);

                                if (nC == ++nD)
                                    break;

                                if (nTemp == target)
                                    vecRet.push_back({ nums[nA], nums[nB], nums[nC], nums[nD] });
                            }
                        }
                    }
                }
            }
        }
        return vecRet;
    }
};
