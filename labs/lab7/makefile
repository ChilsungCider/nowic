# Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
# Signed: 이경민, Student number: 22100487, Class: 02

qsort: quick.o comparator.o printlist.o
	g++ quick.o comparator.o printlist.o -o qsort
quick.o: quick.cpp
	g++ -c quick.cpp -I../../include
comparator.o: comparator.cpp
	g++ -c comparator.cpp
printlist.o: printlist.cpp
	g++ -c printlist.cpp
clean:
	rm -f *.o qsort.exe qsort