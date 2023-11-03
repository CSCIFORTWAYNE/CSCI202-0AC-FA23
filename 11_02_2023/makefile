all: donut main
main: main.cpp donut arrayStack.h linkedStack.h stackADT.h node.h stackTrace
	g++ -pedantic-errors -g main.cpp donut stackTrace -o main
donut: donut.h donut.cpp
	g++ -pedantic-errors -c -g donut.cpp -o donut
stackTrace: stackTrace.h stackTrace.cpp
	g++ -pedantic-errors -c -g stackTrace.cpp -o stackTrace