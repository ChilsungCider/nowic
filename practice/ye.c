#include <stdio.h>

int main()
{
	int days = 0, year = 2020;
	days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

	printf("%d\n", days);

	return 0;
}