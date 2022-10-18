#include <iostream>
using namespace std;

int funnyEars(int funnies)
{
	if (funnies == 0)
		return 0;
	if (funnies % 2 == 0)
		return (3 + funnyEars(funnies - 1));
	return 2 + funnyEars(funnies - 1);
}

int main()
{
	int result = 0;
	result = funnyEars(4);
	cout << result << endl;

	return 0;
}