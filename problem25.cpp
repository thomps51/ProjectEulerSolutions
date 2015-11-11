#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;


int factorial(int n)
{
	  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
int main()
{
	long double start = 0;
	long double start2 = 1;
	long double next = 0;
	int x = 2;
	while(x < 4783)
	{
		next = start + start2;
		cout << next <<endl;
		start = start2;
		start2 = next;
		x++;
	}
}

