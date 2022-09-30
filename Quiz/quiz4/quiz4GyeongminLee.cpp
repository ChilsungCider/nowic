// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#include <iostream>
using namespace std;

struct Car
{
	int age;
	string tag;
};

int main()
{
	Car ur = {25, "cat"};
	Car *my = new Car{20, "sky"};
	Car *we = &ur;
	ur.tag = "hat";
	cout << we->tag << endl;
	delete my;

	return 0;
}