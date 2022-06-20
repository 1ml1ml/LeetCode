#pragma once

#include <iostream>

class CSolution
{
public:
	int myAtoi(std::string s)
	{
		int nRet = 0, nFlag = 0;	//������־λ
		for (auto itrBegin = s.begin(), itrEnd = s.end(); itrBegin != itrEnd; itrBegin++)
		{
			//ȷ��������
			if (0 == nFlag)
			{
				if (*itrBegin == ' ')
					continue;

				if (*itrBegin == '+')
				{
					nFlag = 1;
					continue;
				}

				if (*itrBegin == '-')
				{
					nFlag = -1;
					continue;
				}

				//������ǿո�,+,-���ַ������Ϸ�
				if (*itrBegin < '0' || *itrBegin > '9')
					return 0;

				//��־λĬ��Ϊ��
				nFlag |= 1;
			}

			if (*itrBegin >= '0' && *itrBegin <= '9')
			{
				//����ж�
				if ((INT_MAX / 10 == nRet && *itrBegin - '0' > INT_MAX % 10) || nRet > INT_MAX / 10)
					return INT_MAX;

				//����ж�
				if ((INT_MIN / 10 == nRet && -(*itrBegin - '0') < INT_MIN % 10) || nRet < INT_MIN / 10)
					return INT_MIN;

				nRet = nRet * 10 + nFlag * (*itrBegin - '0');
			}
			//����������ת������
			else break;
		}
		return nRet;
	}
};

