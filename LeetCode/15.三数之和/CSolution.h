#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include <set>

class CSolution 
{
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& vecNum)
	{
		//����
		std::sort(vecNum.begin(), vecNum.end());

		std::vector<std::vector<int>> vecRet;
		for (int nI = 0, nSize = vecNum.size(); nI < nSize; nI++)
		{
			//���˵��ظ�ֵ
			if (0 == nI || vecNum[nI] != vecNum[nI - 1])
			{
				for (int nLeft = nI + 1, nRight = nSize - 1, nTarget = -vecNum[nI]; nLeft < nRight; nLeft++)
				{
					//���˵��ظ�ֵ
					if (nI + 1 == nLeft || vecNum[nLeft] != vecNum[nLeft - 1])
					{
						//�ҵ�<=target�������±�
						while (nLeft < nRight && vecNum[nLeft] + vecNum[nRight] > nTarget)
							nRight--;

						//����±��غ� ����left������ left��right�ĺ�Ҳ���� �����ٳ���<=target��ֵ ֱ�ӷ���
						if (nLeft == nRight)
							break;

						if (vecNum[nLeft] + vecNum[nRight] == nTarget)
							vecRet.push_back({ vecNum[nI], vecNum[nLeft], vecNum[nRight] });
					}
				}
			}
		}
		return vecRet;
	}
};
