#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class CSolution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        recursive(candidates, target);
        return m_vecRet;
    }

private:
    void recursive(std::vector<int>& vec, int target, int index = 0, const std::vector<int>& vecTarget = std::vector<int>(), int num = 0)
    {
        for (int i = index, size = vec.size(); i < size; i++)
        {
            const int& temp = num + vec[i];

            if (temp > target)
                return;

            std::vector<int> vecTemp = vecTarget;
            vecTemp.push_back(vec[i]);

            if (temp == target)
                m_vecRet.push_back(vecTemp);

            recursive(vec, target, i + 1, vecTemp, temp);

            while (i + 1 < size && vec[i] == vec[i + 1])
				i++;
        }
    }

private:
    std::vector<std::vector<int>> m_vecRet;
};
