// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock
{
	int hr, min, sec;
};

using pClock = Clock *;
void tick(pClock ptr);
void show(pClock ptr);
void runs(pClock ptr);

int main(void)
{
	pClock ptr = new Clock{14, 38, 56};

	runs(ptr);

	delete ptr;
	return 0;
}

void tick(pClock ptr)
{
	ptr->sec++;

	// your code here
	if (ptr->sec == 60)
	{
		ptr->sec = 0;
		ptr->min++;
		if (ptr->min == 60)
		{
			ptr->min = 0;
			ptr->hr++;
		}
	}
}

// show the current time in military form.
void show(pClock ptr)
{
	std::cout.fill('0');
	std::cout << std::setw(2) << ptr->hr << ":"
			  << std::setw(2) << ptr->min << ":"
			  << std::setw(2) << ptr->sec << "\r" << std::flush;
}

void runs(pClock clk)
{
	while (true)
	{
		sleep(1);

		tick(clk);
		show(clk);
	}
}