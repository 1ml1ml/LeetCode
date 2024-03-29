#include "CSolution.h"

int main(void)
{
	std::vector<std::vector<char>> vec{ 
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } 
	};

	std::cout << CSolution().isValidSudoku(vec) << std::endl;
	return 0;
}