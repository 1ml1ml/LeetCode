#include "CSolution.h"

int main(void)
{
	for (auto& str : CSolution().letterCombinations(""))
	{
		std::cout << str << std::endl;
	}
	getchar();
	return 0;
}