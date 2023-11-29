all: main graph
main: graph main.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp graph -o main
graph: graph.h graph.cpp unorderedLinkedList.h 
	g++ -pedantic-errors -fdiagnostics-color=always -g -c graph.cpp -o graph