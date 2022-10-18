#include <iostream>
using namespace std;

/*
int *foo1(void)
{
	int x = 10;
	return &x;
}
*/

/*
int *foo2(void)
{
	int *px;
	*px = 10;
	return px;
}
*/

int *foo3(void)
{
	int *px;
	px = new int;
	*px = 10;
	return px;
}

/*
int *foo4(void)
{
	int *px;
	px = new int;
	*px = 10;
	return *px;
}
*/

int main()
{
	int res1 = 0, res2 = 0, res3 = 0;

	// res1 = *foo1();
	// res2 = *foo2();
	res3 = *foo3();
	// res4 = *foo4();

	// cout << res1 << endl;
	// cout << res2 << endl;
	cout << res3 << endl;

	return 0;
}