#pragma once

#include <iostream>
#include <vector>

class CSolution 
{
public:
    int jump(std::vector<int>& nums) 
    {
		//Ì°ÐÄËã·¨
        jump(nums.begin(), nums.end() - 1);
        return m_nCount;
    }

private:
    void jump(decltype(std::vector<int>().begin()) begin, decltype(std::vector<int>().end()) end)
    {
		if (begin < end)
		{
            m_nCount++;

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
    int m_nCount = 0;
};
