// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom.
void printStack(stack<string> orig)
{
	stack<string> temp;
	if (orig.empty())
		return;
	else
	{
		while (!orig.empty())
		{
			temp.push(orig.top());
			orig.pop();
		}
		while (!temp.empty())
		{
			orig.push(temp.top());
			temp.pop();
		}
	}
}

// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens)
{
	stack<string> st;

	for (char token : tokens)
	{
		if (isspace(token))
			continue; // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			assert(st.size() >= 2);
			string temp1 = st.top();
			st.pop();

			string temp2 = st.top();
			st.pop();

			st.push('(' + temp2 + " " + token + " " + temp1 + ')');
		}
		else
		{ // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack
			string tok;
			tok += token;
			st.push(tok);
		}
	}
	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);

	assert(st.size() == 1);
	string result = st.top();
	st.pop();

	DPRINT(cout << "<evaluate() returns "
				<< result << endl;);
	return result;
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens)
{

	for (char token : tokens)
	{
		if (token == '+' || token == '-' || token == '*' || token == '-' || token == ' ')
			return true;
		else if ('0' <= token && token <= '9')
			return true;
		else
			return false;
	}

	return true;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens)
{
	stack<double> st;

	for (char token : tokens)
	{
		if (isspace(token))
			continue; // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// checking the stack top() for right operand
			// checking the stack top() for left oprand
			// compute the expression and push the result

			if (token == '+')
			{
				double temp1 = st.top();
				st.pop();
				double temp2 = st.top();
				st.pop();
				st.push(temp2 + temp1);
			}
			else if (token == '-')
			{
				double temp1 = st.top();
				st.pop();
				double temp2 = st.top();
				st.pop();
				st.push(temp2 - temp1);
			}
			else if (token == '*')
			{
				double temp1 = st.top();
				st.pop();
				double temp2 = st.top();
				st.pop();
				st.push(temp2 * temp1);
			}
			else if (token == '/')
			{
				double temp1 = st.top();
				st.pop();
				double temp2 = st.top();
				st.pop();
				st.push(temp2 / temp1);
			}
		}
		else
		{ // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack
			st.push((double)token - 48);
		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(printStack(st););

	double expr = 0;
	expr = st.top();
	st.pop();

	DPRINT(cout << "<evaluate() returns " << expr << endl;);
	return expr;
}
