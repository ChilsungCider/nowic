// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Stack
{
	T *item;
	int N;
	int capacity;
};

template <typename T>
using stack = Stack<T> *;

template <typename T>
stack<string> newStack(T capacity)
{
	stack<string> s = new Stack<string>;
	s->item = new string[capacity];
	s->N = 0;
	s->capacity = capacity;
	return s;
}

template <typename T>
void free(stack<T> s)
{
	delete[] s->item;
	delete s;
}

template <typename T>
int size(stack<T> s) { return s->N; }

template <typename T>
bool empty(stack<T> s) { return s->N == 0; }

template <typename T>
void pop(stack<T> s) { s->N--; }

template <typename T>
T top(stack<T> s)
{
	return s->item[s->N - 1];
}

template <typename T1, typename T2>
void push(stack<T1> s, T2 item)
{
	s->item[s->N++] = item;
}

template <typename T>
void printStack(stack<T> s)
{
	if (empty(s))
		return;

	string temp = top(s);
	pop(s);
	cout << temp << ' ';
	printStack(s);
	push(s, temp);
}

template <typename T>
void printStack_fromBottom(stack<T> s)
{
	if (size(s) == 1)
	{
		cout << top(s) << ' ';
	}
	else
	{
		string temp = top(s);
		pop(s);
		printStack_fromBottom(s);
		cout << temp << ' ';
		push(s, temp);
	}
}

int main()
{
	string list[] = {"to", "be", "or", "not", "to", "-", "be",
					 "-", "-", "that", "-", "-", "-", "is"};
	stack<string> s = newStack(size(list));

	for (auto item : list)
	{
		if (item != "-")
			push(s, item);
		else
		{
			cout << top(s) << ' ';
			pop(s);
		}
	}

	cout << "\nsize : " << size(s);
	cout << "\ntop : " << top(s);
	cout << "\nstack T: ";
	printStack(s);
	cout << "\nstack B: ";
	printStack_fromBottom(s);
	cout << "\nHappy Coding";

	free(s);
	return 0;
}