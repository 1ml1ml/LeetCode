#pragma once

#include <iostream>
#include <vector>

class CSolution 
{
public:
    int jump(std::vector<int>& nums) 
    {
		//̰���㷨
        jump(nums.begin(), nums.end() - 1);
        return m_count;
    }

private:
    void jump(decltype(std::vector<int>().begin()) begin, decltype(std::vector<int>().end()) end)
    {
		if (begin < end)
		{
            m_count++;

			auto itrFar = begin + *begin;
			for (auto itrBegin = begin + 1, itrEnd = itrFar; itrFar < end && itrBegin <= itrEnd; itrBegin++)
			{
				if (itrBegin + *itrBegin > itrFar + *itrFar)
					itrFar = itrBegin;
			}
			jump(itrFar, end);
		}
    }

private:
    int m_count = 0;
};
