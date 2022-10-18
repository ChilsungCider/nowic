#include <iostream>

struct Node
{
	int item;
	Node *next;
};
using pNode = Node *;
pNode push_front(pNode h, int val);
pNode pop_front(pNode h, int *val);
pNode show(pNode h);

pNode stacked(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		pNode h = push_front(h, a[i]);

		return h;
	}
}