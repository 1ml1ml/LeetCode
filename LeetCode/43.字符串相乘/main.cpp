#include "CSolution.h"

int main(void)
{
	int x = 123, y = 456;
	std::string ret = CSolution().multiply(std::to_string(x), std::to_string(y));
	std::cout << "�ַ���:" << ret << std::endl;
	std::cout << "��ȷֵ:" << (long long)x * y << std::endl;
	return 0;
}