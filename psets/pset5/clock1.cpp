// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
#include <iomanip>

struct Clock
{
	int hr, min, sec;
};

void tick(Clock *ptr);
void show(Clock *ptr);

int main(void)
{
	Clock clock = {14, 38, 56};

	for (int i = 0; i < 6; ++i)
	{
		tick(&clock);
		show(&clock);
	}

	return 0;
}

void tick(Clock *ptr)
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
void show(Clock *ptr)
{
	std::cout.fill('0');
	std::cout << std::setw(2) << ptr->hr << ":"
			  << std::setw(2) << ptr->min << ":"
			  << std::setw(2) << ptr->sec << std::endl;
}