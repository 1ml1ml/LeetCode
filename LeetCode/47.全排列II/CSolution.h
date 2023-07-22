#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class CSolution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        recursion(nums, std::vector<bool>(nums.size(), false), std::vector<int>(), ret);
        return ret;
    }

private:
    void recursion(const std::vector<int>& nums, std::vector<bool> used, std::vector<int> path, std::vector<std::vector<int>>& ret)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
		}

        for (auto index = 0; index < nums.size(); ++index)
        {
            if (true == used[index] || ( index > 0 && nums[index] == nums[index - 1]  && false == used[index - 1]))
                continue;

            used[index] = true;
            path.push_back(nums[index]);
            recursion(nums, used, path, ret);
            path.pop_back();
            used[index] = false;
        }
    }

    /*void recursion(std::vector<int>& nums, std::vector<std::vector<int>>& ret, int begin)
    {
        if (begin == nums.size())
        {
            ret.push_back(nums);
            return;
        }

        for (auto index = begin; index < nums.size(); ++index)
        {
            if (index > begin && nums[index] == nums[index - 1])
                continue;

            std::swap(nums[begin], nums[index]);
            recursion(nums, ret, begin + 1);
            std::swap(nums[begin], nums[index]);
        }
    }*/
};
