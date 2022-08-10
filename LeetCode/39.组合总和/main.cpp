#include "CSolution.h"

int main(void)
{
	std::vector<int> vec{ 10,1,2,7,6, 5 };
	for (auto& vec : CSolution().combinationSum(vec, 8))
	{
		std::cout << "[";
		for (auto& num : vec)
			std::cout << " " << num << ",";
		std::cout << "]" << std::endl;
	}
	return 0;
}