#include <iostream>
#include "CSolutionh.h"

int main(void)
{
	std::vector<int> vec{ -2, -2, -2, -2, -2,-5,1,6,0,-1,4,5 };
	std::cout << CSolution().threeSumClosest(vec, 5);
	getchar();

	return 0;
}