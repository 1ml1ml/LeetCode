#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

class CSolution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        m_vecRet.clear();
        recursion(nums, 0, nums.size());
        return m_vecRet;
    }

private:
    void recursion(std::vector<int>& nums, int begin, int end)
    {
        if (begin == end)
            m_vecRet.push_back(nums);
        else
        {
            for (int i = begin; i != end; i++)
            {
                //将选中的数放在nums的最前面,[0,begin]表示当前排列,[begin+1,end)表示剩余可选中的数
                std::swap(nums[i], nums[begin]);
                recursion(nums, begin + 1, end);
                std::swap(nums[i], nums[begin]);
            }
        }
    }

private:
    std::vector<std::vector<int>> m_vecRet;
};