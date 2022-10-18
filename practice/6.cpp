#include <iostream>
using namespace std;

int main()
{
	int i, j, sum = 0, N = 8;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j = j * 2)
		{
			sum++;
			cout << j << " ";
			// cout << sum << " ";
		}
	}

	return 0;
}