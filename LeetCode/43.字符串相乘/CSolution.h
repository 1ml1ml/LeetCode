#pragma once

#include <iostream>
#include <string>

#include <iostream>
#include <string>

class CSolution
{
public:
	std::string multiply(std::string num1, std::string num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";

		if (num1 == "1")
			return num2;

		if (num2 == "1")
			return num1;

		if (num1.size() > num2.size())
			std::swap(num1, num2);

		std::string strRet("0");
		for (auto itr1 = num1.rbegin(); itr1 != num1.rend(); itr1++)
		{
			if (*itr1 != '0')
			{
				int overflow = 0;
				std::string strAddNeed(itr1 - num1.rbegin(), '0');
				for (auto itr2 = num2.rbegin(); itr2 != num2.rend(); itr2++)
				{
					overflow += (*itr1 - '0') * (*itr2 - '0');
					strAddNeed.push_back(overflow % 10 + '0');
					overflow /= 10;
				}

				if (0 != overflow)
					strAddNeed.push_back(overflow + '0');
				std::reverse(strAddNeed.begin(), strAddNeed.end());
				strRet = strAdd(strRet, strAddNeed);
			}
		}
		return strRet;
	}

private:
	std::string strAdd(std::string& str1, std::string& str2)
	{
		if ("0" == str1)
			return str2;
		if ("0" == str2)
			return str1;

		if (str2.size() > str1.size())
			std::swap(str1, str2);

		std::string strRet;
		int overflow = 0;
		for (auto itr1 = str1.rbegin(), itr2 = str2.rbegin(); itr1 != str1.rend(); itr1++)
		{
			overflow += *itr1 - '0' + (itr2 != str2.rend() ? *itr2++ - '0' : 0);
			strRet.push_back(overflow % 10 + '0');
			overflow /= 10;
		}

		if (0 != overflow)
			strRet.push_back(overflow + '0');
		std::reverse(strRet.begin(), strRet.end());

		return strRet;
	}
};
