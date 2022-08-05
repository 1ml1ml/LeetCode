#pragma once

#include <iostream>
#include <vector>

class CSolution
{
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
		auto begin = nums.begin(), end = nums.end();
        auto itr = binarySearch(begin, end, target);

		if (itr != end && *itr == target)
		{
			auto last = itr;
			while (last + 1 < end && *(last + 1) == *last)
				last++;

			auto first = itr;
			while (first - 1 >= begin && *(first - 1) == *first)
				first--;

			return { static_cast<int>(first - begin), static_cast<int>(last - begin) };
		}
		else return { -1, -1 };
    }
    
private:
    decltype(std::vector<int>().begin()) binarySearch(decltype(std::vector<int>().begin()) begin, decltype(std::vector<int>().end()) end, int target)
    {
		if (begin == end)
			return end;

		auto mid = begin + (end - 1 - begin >> 1);
		if (*mid == target)
			return mid;
		else if (target < *mid)
			return binarySearch(begin, mid, target);
		else return binarySearch(mid + 1, end, target);
    }
};
