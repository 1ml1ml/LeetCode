#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
std::next_permutation
���������������㷨, ���ڳ���Ϊn������a:
1.���ȴӺ���ǰ���ҵ�һ��˳���(i, i + 1), ����a[i] < a[i + 1].��������С������Ϊa[i]����ʱ[i + 1, n) ��Ȼ���½�����.
2.����ҵ���˳���, ��ô������[i + 1, n)�дӺ���ǰ���ҵ�һ��Ԫ��j����a[i] < a[j].�������ϴ�������Ϊa[j].
3.����a[i]��a[j], ��ʱ����֤������[i + 1, n)��Ϊ�������ǿ���ֱ��ʹ��˫ָ�뷴ת����[i + 1, n)ʹ���Ϊ����, ������Ը������������.
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
