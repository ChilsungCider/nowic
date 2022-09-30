// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
using namespace std;

long long unsigned factorial(int n)
{
	if (n == 1 || n == 0)
		return n;
	auto result = n * factorial(n - 1);
	return result;
}

int main()
{
	int n[] = {1, 2, 3, 4, 5, 8, 12, 20};
	for (auto x : n)
		cout << "factorial(" << x << ") = " << factorial(x) << endl;
	return 0;
}