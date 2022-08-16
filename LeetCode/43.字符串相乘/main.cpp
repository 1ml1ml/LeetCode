#include "CSolution.h"

int main(void)
{
	int x = 99999, y = 9999;
	std::cout << CSolution().multiply(std::to_string(x), std::to_string(y)) << std::endl;
	std::cout << x * y << std::endl;

	return 0;
}