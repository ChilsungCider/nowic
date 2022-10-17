// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

// infixall.cpp :
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
//
#include <iostream>
#include <cassert>
#include <cmath>
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
struct stack {
    vector<T> item;

    bool empty() const {
        return item.empty();
    }
    auto size() const {
        return item.size();
    }
    void push(T const& data) {
        item.push_back(data);
    }
    void pop() {
        if (item.empty())
            throw out_of_range("stack<>::pop(): pop stack");
        item.pop_back();
    }
    T top() const {
        if (item.empty())
            throw out_of_range("stack<>::top(): top stack");
        return item.back();
    }
};
#else /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

int precedence(char op)
{
	if (op == '(')
		return 0;
	else if (op == '+')
		return 1;
	else if (op == '-')
		return 1;
	else if (op == '*')
		return 2;
	else if (op == '/')
		return 2;
	else if (op == '^')
		return 3;
	else
		return 0;
}

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
	// cout << endl;
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
	case '^':
		return pow(a, b);
	}

	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

// there is a bug... bug: int -> double , right first
double compute(stack<double> &va_stack, stack<char> &op_stack)
{
	double right = va_stack.top();
	va_stack.pop();
	double left = va_stack.top();
	va_stack.pop();
	char op = op_stack.top();
	op_stack.pop();
	double value = apply_op(left, right, op);

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
	int k = 1;

	for (size_t i = 0; i < tokens.length(); i++)
	{
		// token is a whitespace or an opening brace, skip it.
		if (isspace(tokens[i]))
			continue;

		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a value(or operand), push it to va_stack.
		if (isdigit(tokens[i]))
		{
			int ivalue = 0;
			ivalue = tokens[i] - '0';
			// cout << "your code here: to handle multi-digits(operand)\n";

			if (k == 1)
			{
				va_stack.push(ivalue);
				k++;
			}

			else
			{
				double temp1 = va_stack.top();
				va_stack.pop();
				double temp2 = ivalue + temp1 * 10;
				va_stack.push(temp2);
				k++;
			}
		}
		else if (tokens[i] == '(')
		{
			op_stack.push(tokens[i]);
			op_stack.top();
		}

		else if (tokens[i] == ')')
		{ // compute it, push the result to va_stack
			// do
			// {
			//     value = compute(va_stack, op_stack);
			//     va_stack.push(value);
			// } while (op_stack.top() == '(');
			// op_stack.pop();
			int t = op_stack.size();
			for (int i = 0; i < t; i++)
			{
				if (op_stack.top() == '(')
				{
					op_stack.top();
					op_stack.pop();
					break;
				}
				va_stack.push(compute(va_stack, op_stack));
			}

			k = 1;
		}
		else
		{ // token is an operator; push it to op_stack.
			if (op_stack.empty() || op_stack.top() == '(')
			{
				op_stack.size();
				op_stack.push(tokens[i]);
			}
			else
			{
				if (precedence(tokens[i]) > precedence(op_stack.top()))
				{
					op_stack.push(tokens[i]);
				}
				else
				{
					va_stack.push(compute(va_stack, op_stack));
					op_stack.push(tokens[i]);
				}
			}

			k = 1;
		}
	}

	int len = 0;
	len = op_stack.size();

	for (int i = 0; i < len; i++)
	{
		double temp1 = va_stack.top();
		va_stack.pop();
		double temp2 = va_stack.top();
		va_stack.pop();
		char ot = op_stack.top();
		op_stack.pop();

		/*
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
		else if (ot == '^')
		{
			va_stack.push(pow(temp2, temp1));
			break;
		}
		else
			break;
		*/
		switch (ot)
		{
		case '+':
		{
			va_stack.push(temp2 + temp1);
			break;
		}
		case '-':
		{
			va_stack.push(temp2 - temp1);
			break;
		}
		case '*':
		{
			va_stack.push(temp2 * temp1);
			break;
		}
		case '/':
		{
			va_stack.push(temp2 / temp1);
			break;
		}
		case '^':
		{
			va_stack.push(pow(temp2, temp1));
			break;
		}
		default:
			break;
		}
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