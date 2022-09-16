// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// selection sort
// The selection sort improves on the bubble sort by making only one exchange
// for every pass through the list. In order to do this, a selection sort
// looks for the largest value as it makes a pass and, after completing the
// pass, places it in the proper location. As with a bubble sort, after the
// first pass, the largest item is in the correct place. After the second pass,
// the next largest is in place. This process continues and requires n−1 passes
// to sort n items, since the final item must be in place after the (n−1)st pass.
// Its time complexity is O(n^2).
//
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added
//
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first.
// > g++ -std=c++11 selection.cpp -o selection
// > ./selection
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG selection.cpp -o selection
// > ./selection
//
// To add this function to a static library libsort.a,
// 1. set #if 0 to deactivate main() function at the bottom of the file first.
// 2. compile first to produce ~.o file.
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c selection.cpp      # produce selection.o
// > ar r libsort.a selection.o           # insert or update selection.o in libsort.a
// > ar t libsort.a                       # show objects in libsort.a
//
/******************************************************************************
  Lab05 - Understanding a better coding in C/C++
  - NMN(No magic number)
  - DRY(Don't repeat yourself)
  - Use new and delete instead of malloc(), free()
  - Use assert() after new to check the memory allocation status
  - rand() and mod operator %
  - Learn about a better coding after all.
*******************************************************************************/
#include <iostream>
using namespace std;

void printlist(int *list, int n, int show_n = 20, int per_line = 10);

void sort(int *list, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		int temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

#if 0
int main(int argc, char *argv[])
{
	int list[] = {3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	int n = sizeof(list) / sizeof(int);

	// use printlist() to show the list initialized
	cout << "UNSORTED(" << n << "): " << endl;
	printlist(list, sizeof(list) / sizeof(int), 20, 10);

	// ascending order
	sort(list, n);
	cout << "SORTED(" << n << "): " << endl;
	printlist(list, sizeof(list) / sizeof(int), 20, 10);

	cout << ("Happy Coding~~\n");

	return 0;
}
#else
void selectionsort(int *list, int n, bool (*comp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (comp(list[j + 1], list[j]))
			{
				swapped = true;
				swap(list[j + 1], list[j]);
			}
		}
	}
}

bool more(int x, int y)
{
	if (x > y)
		return true;
	else
		return false;
}

bool less(int x, int y)
{
	if (x < y)
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	// int n = 10;
	int n = 0;
	int temp = 0, same = 0;
	string q;
	while (1)
	{
		cout << "Enter a number of samples to sort(q to quit): ";
		getline(cin, q);
		if (q == "q")
			break;
		try
		{
			stoi(q);
		}
		catch (const invalid_argument)
		{
			cout << "Retry -" << endl;
			continue;
		}

		if (stoi(q) <= 1)
			cout << "Retry -" << endl;
		else
			break;
	}
	n = stoi(q);
	int *list = new (nothrow) int[n];
	assert(list != nullptr);

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % n + 1;
		temp = list[i];
		for (int j = 0; j < i; j++)
		{
			if (list[j] == temp)
			{
				i--;
				same++;
			}
		}
	}

	// use printlist() to show the list initialized
	cout << "UNSORTED(" << n << "): " << endl;
	printlist(list, n);
	cout << endl;

	// ascending order
	sort(list, n);
	cout << "SORTED(" << n << ") " << endl;
	printlist(list, n);
	cout << endl;

	selectionsort(list, n, more);
	cout << "SORTED(" << n << "): descending using fp" << endl;
	printlist(list, n);
	cout << endl;

	cout << "Happy Coding~~" << endl;

	delete[](list);
	return 0;
}
#endif
