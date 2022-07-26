#pragma once

#include <iostream>
#include <vector>

class CSolution 
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        int left = 0;
        for (int right = left, size = nums.size(); right < size; right++)
        {
            if (nums[right] != val)
                nums[left++] = nums[right];
        }
        return left;
    }
};
