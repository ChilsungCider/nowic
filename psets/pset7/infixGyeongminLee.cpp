// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.05	created and assert() added
//
#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0 //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack
{
	vector<T> item;

	bool empty() const
	{
		return item.empty();
	}
	auto size() const
	{
		return item.size();
	}
	void push(T const &data)
	{
		item.push_back(data);
	}
	void pop()
	{
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const
	{
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};

#else /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
void printStack(stack<T> orig)
{
	if (orig.size() == 1)
	{
		cout << orig.top() << ' ';
	}
	else
	{
		T temp = orig.top();
		orig.pop();
		printStack(orig);
		orig.push(temp);
	}

	cout << endl;
}

// performs arithmetic operations.
double apply_op(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

// there is a bug...
double compute(stack<double> &va_stack, stack<char> &op_stack)
{
	double left = va_stack.top();
	va_stack.pop();
	double right = va_stack.top();
	va_stack.pop();
	char op = op_stack.top();
	op_stack.pop();
	double value = apply_op(right, left, op);

	DPRINT(cout << " va/op_stack.pop: " << value << endl;);
	return value;
}

// returns value of expression after evaluation.
double evaluate(string tokens)
{
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<double> va_stack; // stack to store operands or values
	stack<char> op_stack;	// stack to store operators.
	double value = 0;
	int n = 1;

	for (size_t i = 0; i < tokens.length(); i++)
	{
		// token is a whitespace or an opening brace, skip it.
		if (isspace(tokens[i]) || tokens[i] == '(')
			continue;
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a value(or operand), push it to va_stack.
		if (isdigit(tokens[i]))
		{
			int ivalue = 0;
			ivalue = tokens[i] - '0';
			if (n == 1)
			{
				va_stack.push(ivalue);
				n++;
			}
			else
			{
				double temp1 = va_stack.top();
				va_stack.pop();
				double temp2 = ivalue + temp1 * 10;
				va_stack.push(temp2);
				n++;
			}
		}
		else if (tokens[i] == ')')
		{ // compute it, push the result to va_stack
			value = compute(va_stack, op_stack);
			va_stack.push(value);
			n = 1;
		}
		else
		{ // token is an operator; push it to op_stack.
			op_stack.push(tokens[i]);
			n = 1;
		}
	}

	for (int i = 0; i < op_stack.size(); i++)
	{
		double temp1 = va_stack.top();
		va_stack.pop();
		double temp2 = va_stack.top();
		va_stack.pop();
		char ot = op_stack.top();
		op_stack.pop();

		if (ot == '+')
		{
			va_stack.push(temp2 + temp1);
			break;
		}
		else if (ot == '-')
		{
			va_stack.push(temp2 - temp1);
			break;
		}
		else if (ot == '*')
		{
			va_stack.push(temp2 * temp1);
			break;
		}
		else if (ot == '/')
		{
			va_stack.push(temp2 / temp1);
			break;
		}
		else
			break;
	}

	DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
	DPRINT(printStack(va_stack); cout << endl;);
	DPRINT(printStack(op_stack); cout << endl;);

	if (!op_stack.empty())
	{
		printf("\n");
		assert(op_stack.empty());
	}
	value = va_stack.top();
	va_stack.pop();

	return value;
}
