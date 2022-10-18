#include <iostream>

int joy(int a, int b)
{
	return a * b * 1004;
}

int main()
{
	int fp;
	fp = joy(1, 1);
	std::cout << "Joy: " << fp;

	return 0;
}