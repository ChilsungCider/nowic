// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#ifndef _CLOCKGYEONGMINLEE_H_
#define _CLOCKGYEONGMINLEE_H_

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock
{
	int hr, min, sec;
};

using pClock = Clock *;

void tick(pClock clk);
void show(pClock clk, char end = '\n');
void runs(pClock clk, char end = '\n');

#endif