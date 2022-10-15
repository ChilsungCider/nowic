// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
#include <string>

using namespace std;

struct Stack
{
	string *item;
	int N;
	int capacity;
};

using stack = Stack *;

void resize(stack s, int new_capacity)
{
	string *copied = new string[new_capacity];
	for (int i = 0; i < s->N; i++)
		copied[i] = s->item[i];
	delete[] s->item;
	s->item = copied;
	s->capacity = new_capacity;
}

stack newStack(int capacity = 1)
{
	stack s = new Stack;
	s->item = new string[capacity];
	s->N = 0;
	s->capacity = capacity;
	return s;
}

void free(stack s)
{
	delete[] s->item;
	delete s;
}

int size(stack s) { return s->N; }
bool empty(stack s) { return s->N == 0; }
void pop(stack s)
{
	s->N--;
	if (s->capacity != 1)
		resize(s, s->capacity - 1);
}

string top(stack s) { return s->item[s->N - 1]; }

void push(stack s, string item)
{
	if (s->capacity == s->N)
		resize(s, s->capacity + 1);
	s->item[s->N++] = item;
}

void printStack(stack s)
{
	if (empty(s))
		return;

	string temp = top(s);
	pop(s);
	cout << temp << ' ';
	printStack(s);
	push(s, temp);
}

void printStack_fromBottom(stack s)
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

	stack s = newStack(size(list));

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