#include "CSolution.h"

int main(void)
{
	for (auto& str : CSolution().generateParenthesis(3))
		std::cout << str << std::endl;
}