#include <iostream>

#include "CSolution.h"

int main(void)
{
	std::vector<int> vec = { -1,0,1,2,-1,-4 };
	for (auto& v : CSolution().threeSum(vec))
	{
		std::cout << "{ ";
		for (auto& n : v)
		{
			std::cout << n << ' ';
		}
		std::cout << "}" << std::endl;
	}
	getchar();
	return 0;
}