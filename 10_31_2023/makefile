all: donut main
main: main.cpp donut linkedList.h unorderedLinkedList.h linkedListIterator.h
	g++ -pedantic-errors -g main.cpp donut -o main
donut: donut.h donut.cpp
	g++ -pedantic-errors -c -g donut.cpp -o donut