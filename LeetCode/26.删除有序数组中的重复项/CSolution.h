#pragma once

#include <iostream>
#include <vector>

class CSolution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int left = 1;
        for (int right = left, size = nums.size(); right < size; right++)
        {
            if (nums[right] != nums[right - 1])
                nums[left++] = nums[right];
        }
        return left;
    }
};
