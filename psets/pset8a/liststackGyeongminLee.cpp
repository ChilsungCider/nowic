// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

// liststack.cpp
// This program implements a stack using singly-linked list
// without a head structure and without sentinel nodes. It simply links
// node to node. The caller is responsible for maintaining the the first
// node (head) of the list. Most functions need the first node to work
// with the list and returns the first node of the list since it may be
// changed inside of the functions.
//
// author: idebtor@gmail.com
#include "liststack.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.

pNode clear(pNode p)
{
	if (empty(p))
		return nullptr;
	Node *curr = p;
	while (curr != nullptr)
	{
		Node *zap = curr;
		curr = curr->next;
		delete zap;
	}
	cout << "\n\tCleared...\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p)
{
	if (empty(p))
		return 0;
	int count = 0;
	// cout << "your code here\n";
	while (p != nullptr)
	{
		p = p->next;
		count++;
	}
	return count;
}

// sets the min and max values that are passed as references in the list
void minmax(pNode p, int &min, int &max)
{
	if (empty(p))
	{
		min = max = 0;
		return;
	}
	// cout << "your code here\n";
	min = 999999, max = -999999;

	Node *curr = p;
	while (curr != nullptr)
	{
		if (curr->data > max)
			max = curr->data;
		if (curr->data < min)
			min = curr->data;
		curr = curr->next;
	}
	return;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p)
{
	if (p == nullptr)
		return true;
	else
		return false;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by N.
pNode push(pNode p, int val, int N)
{
	DPRINT(cout << ">push val=" << val << " N=" << N << endl;);
	// cout << "your code here\n";
	val += N - 1;
	p = new Node{val, p};
	val -= N;
	while (N > 1)
	{
		Node *curr = p;
		p->next = new Node{++val, p->next};
		curr = curr->next;
		N--;
	}
	DPRINT(cout << "<push size=" << size(p) << endl;);
	return p;
}

// removes N nodes in the list and returns the new first node.
// This deallocates the removed node, effectively reduces its size by N.
pNode pop(pNode p, int N)
{
	DPRINT(cout << ">pop size=" << size(p) << " N=" << N << endl;);
	if (empty(p))
		return nullptr;
	// cout << "your code here\n";
	int count = 0;
	while (1)
	{
		if (count == N)
			break;
		Node *pop = p;
		p = p->next;
		delete pop;
		count++;
	}
	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// returns the first node in the list. This does not destroy the node.
pNode top(pNode p)
{
	// cout << "your code here\n";
	if (!empty(p))
		return p;
	return nullptr;
}

// shows all the list elements, show_n items per line  if all is true.
// shows the first and the last show_n items in the list if all is false.
void show(pNode p, bool all, int show_n)
{
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p))
	{
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	pNode show;
	const int N = size(p);
	cout << endl
		 << "TOP ";
	if (all || N <= show_n * 2)
	{
		for (i = 1, show = p; show != nullptr; show = show->next, i++)
		{
			cout << "\t" << show->data;
			if (i % show_n == 0)
				cout << endl;
		}
		return;
	}
	// print the first show_n items
	show = p;
	for (int i = 0; i < N - show_n; i++)
	{
		if (i >= show_n)
		{
			p = p->next;
			continue;
		}
		cout << "\t" << p->data;
		p = p->next;
	}
	cout << "\n...left out...\n";
	// print the last show_n items
	// Firstly, move the pointer to the place where show_n items are left.
	// cout << "your code here\n";
	for (pNode show = p; show != nullptr; show = show->next)
	{
		cout << "\t" << show->data;
	}
	cout << endl;
}
