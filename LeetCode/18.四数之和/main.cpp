#include "CSolution.h"

int main(void)
{
	std::vector<int> vecIn = { 2, 2, 2 ,2, 2 };
	for (auto& vec : CSolution().fourSum(vecIn, 8))
	{
		std::cout << "[ ";
		for (auto& n : vec)
		{
			std::cout << n << ' ';
		}
		std::cout << " ]" << std::endl;
	}
	getchar();
	return 0;
}