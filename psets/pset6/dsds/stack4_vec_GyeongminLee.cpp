// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack
{
	vector<string> item;
};

using stack = Stack *;

void free(stack s)
{
	delete s;
}

int size(stack s)
{
	return s->item.size();
}

bool empty(stack s)
{
	return s->item.empty();
}

void pop(stack s)
{
	s->item.pop_back(); // 벡터 맨 뒤 원소 삭제
}

void push(stack s, string item)
{
	s->item.push_back(item);
}

string top(stack s)
{
	return s->item.back();
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
	stack s = new Stack;

	for (auto item : list)
	{
		if (item != "-")
		{
			push(s, item);
		}
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
