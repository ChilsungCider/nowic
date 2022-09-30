// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
#include <iomanip>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

template <typename T>
T binarysearch(T *data, int key, int lo, int hi)
{
	DPRINT(cout << "key=" << key << " lo=" << lo << " hi=" << hi << endl;);

	int mid = lo + (hi - lo) / 2;
	if (lo > hi)
		return mid;
	if (data[mid] == key)
		return mid;
	else if (data[mid] > key)
		return binarysearch(data, key, lo, mid - 1);
	else
		return binarysearch(data, key, mid + 1, hi);
}

// randomly generate a key to search between list[0] and list[size-1].
template <typename T>
T get_a_key(T *list, int size)
{
	int key = rand() % (list[size - 1] + 1 - list[0]) + list[0];
	return key;
}

// calls binarysearch(data, key, lo, hi) "size" number of times
// while generating a new random key at every call of the function.
// and also displays the results. If the key is found in the list,
// it displays its index in the list. If the key is not found, it
// displays where it is supposed to be appeared if there is one.
template <typename T>
void binarysearch(T *list, int size)
{
	DPRINT(cout << ">binarysearch: size=" << size << endl;)
	auto key = get_a_key(list, size);
	int idx = binarysearch(list, key, 0, size);

	if (list[idx] == key)
		cout << "\t" << key << "\tis\t@List[" << idx << "]\n";
	else
		cout << "\t" << key << "\tis  not @List[" << idx << "]\n";
	DPRINT(cout << "<binarysearch\n";)
}

//////// The following code is the same in binsearchDriver.cpp //////////
//////// This is given at your convenience. /////////////////////////////
#if 1
int main()
{
	// char list[] = { 'a', 'c', 'e', 'g' };
	char list[] = {'a', 'c', 'e', 'g', 'i', 'k'};
	// int list[] = {0, 1, 4, 6};
	// int list[] = {3, 5, 6, 8, 9, 11};

	int size = sizeof(list) / sizeof(list[0]);
	srand((unsigned)time(nullptr)); // turn off this line during debugging

	cout << "  list: ";
	for (auto x : list)
		cout << x << " ";
	cout << endl;

	for (int i = 0; i < size; i++)
		binarysearch(list, size);
}
#endif