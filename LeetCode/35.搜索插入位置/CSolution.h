#pragma once

#include <iostream>
#include <vector>

class CSolution 
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        auto itr = binarySearch(nums.begin(), nums.end(), target);
        auto ret = itr - nums.begin();
        return ret;
    }

private:
    decltype(std::vector<int>().begin()) binarySearch(decltype(std::vector<int>().begin()) begin, decltype(std::vector<int>().end()) end, int target)
    {
        if (begin >= end)
            return end;
        auto mid = begin + (end - 1 - begin >> 1);
        if (target == *mid)
            return mid;
        else if (target < *mid)
            return binarySearch(begin, mid, target);
        else return binarySearch(mid + 1, end, target);
    }
};
