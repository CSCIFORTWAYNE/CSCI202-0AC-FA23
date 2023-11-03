all: donut main
main: main.cpp donut arrayStack.h linkedStack.h stackADT.h node.h
	g++ -pedantic-errors -g main.cpp donut -o main
donut: donut.h donut.cpp
	g++ -pedantic-errors -c -g donut.cpp -o donut