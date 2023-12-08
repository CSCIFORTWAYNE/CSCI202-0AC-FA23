all: block blockchain main.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g  main.cpp block blockchain -lcrypto -o main
block: block.hpp block.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g -c block.cpp -o block
blockchain: blockchain.hpp blockchain.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g -c blockchain.cpp -o blockchain