teststack: test.cpp stack.cpp stack.hpp
	g++ test.cpp -c
	g++ stack.cpp -c
	g++ test.o stack.o -o teststack
	rm test.o stack.o
