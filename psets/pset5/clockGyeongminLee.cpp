// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include "clockGyeongminLee.h"

void tick(pClock clk)
{
	clk->sec++;

	// your code here
	if (clk->sec == 60)
	{
		clk->sec = 0;
		clk->min++;
		if (clk->min == 60)
		{
			clk->min = 0;
			clk->hr++;
		}
	}
}

void show(pClock clk, char end)
{
	std::cout.fill('0');
	std::cout << std::setw(2) << clk->hr << ":"
			  << std::setw(2) << clk->min << ":"
			  << std::setw(2) << clk->sec << end;
}

void runs(pClock clk, char end)
{
	while (true)
	{
		sleep(1);

		// tick(clk);
		clk->sec++;

		if (clk->sec == 60)
		{
			clk->sec = 0;
			clk->min++;
			if (clk->min == 60)
			{
				clk->min = 0;
				clk->hr++;
			}
		}

		// show(clk);
		std::cout.fill('0');
		std::cout << std::setw(2) << clk->hr << ":"
				  << std::setw(2) << clk->min << ":"
				  << std::setw(2) << clk->sec << end << std::flush;
	}
}