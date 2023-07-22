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
                //��ѡ�е�������nums����ǰ��,[0,begin]��ʾ��ǰ����,[begin+1,end)��ʾʣ���ѡ�е���
                std::swap(nums[i], nums[begin]);
                recursion(nums, begin + 1, end);
                std::swap(nums[i], nums[begin]);
            }
        }
    }

private:
    std::vector<std::vector<int>> m_vecRet;
};