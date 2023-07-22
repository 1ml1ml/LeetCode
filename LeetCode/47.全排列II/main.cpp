#include "CSolution.h"

int main(void)
{
	std::vector<int> vecNum = {1, 1, 2, 3};
	for (auto& vec : CSolution().permuteUnique(vecNum))
	{
		std::cout << "[";
		for (auto& num : vec)
			std::cout << num << ",";
		std::cout << "]" << std::endl;
	}
	return 0;
}