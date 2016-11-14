all: program.cpp 
	g++ -O3 -std=c++11 -g -Wall -o myprog program.cpp fraction.cpp
