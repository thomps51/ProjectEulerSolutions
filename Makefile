COMPILER = g++-4.9
COMPILER_FLAGS = -c -g -O0 -Wall -Werror
LINKER = g++-4.9

all: euler

euler.o: euler.cpp
	g++-4.9 -c -g -O0 -Wall euler.cpp
euler: euler.o
	g++-4.9 euler.o -o euler
