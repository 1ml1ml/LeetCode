#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class CSoultion
{
public:
    int search(std::vector<int>& nums, int target) 
    {
		auto begin = nums.begin(), end = nums.end();
        if (*begin > nums.back())
        {
            while (begin + 1 != end)
            {
                auto next = begin + 1;
                if (*begin > *next)
                {
                    if (target >= nums.front())
                        begin = nums.begin(), end = next;
                    else begin = next;
                    break;
                }
                begin++;
            }
        }
        auto ret = binarySearch(begin, end, target);
        return ret != end && *ret == target ? ret - nums.begin() : -1;

        /*
        *auto ret = std::lower_bound(begin, end, target);
        *return ret != end && *ret == target ? ret - nums.begin() : -1;
        */
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
