#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
std::next_permutation
我们这样描述该算法, 对于长度为n的排列a:
1.首先从后向前查找第一个顺序对(i, i + 1), 满足a[i] < a[i + 1].这样「较小数」即为a[i]。此时[i + 1, n) 必然是下降序列.
2.如果找到了顺序对, 那么在区间[i + 1, n)中从后向前查找第一个元素j满足a[i] < a[j].这样「较大数」即为a[j].
3.交换a[i]与a[j], 此时可以证明区间[i + 1, n)必为降序。我们可以直接使用双指针反转区间[i + 1, n)使其变为升序, 而无需对该区间进行排序.
*/

class CSolution
{
public:
	void nextPermutation(std::vector<int>& nums)
	{
		int size = nums.size(), first = -1, second = size - 1;
		for (int i = size - 1; i - 1 >= 0; i--)
		{
			if (nums[i - 1] < nums[i])
			{
				for (first = i - 1; second > first; second--)
				{
					if (nums[second] > nums[first])
					{
						std::swap(nums[first], nums[second]);
						break;
					}
				}
				break;
			}
		}
		std::reverse(nums.begin() + first + 1, nums.end());
	}
};
