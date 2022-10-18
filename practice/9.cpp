#include <iostream>
#include <stack>
using namespace std;
template <typename T>
struct Stack{
	int n;
};

void fun(int n)
{
	Stack S = new Stack;
	while (n > 0)
	{
		S.push(&S, n % 2);
		n = n / 2;
	}
	while (!S.empty(&S))
		cout << S.pop(&S) << endl;
}

int main()
{
	fun(6);

	return 0;
}