#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <ctime>
using namespace std;


int factorial(int n)
{
	  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
bool primeTest(double n)
{
	if(n < 0)
		return false;
	bool test = true;
	for(int j = 2;j<=sqrt(n);j++)
	{
		if(fmod(n,j)==0)
			test=false;
	}
	return test;
}
int testN(int N, char c)
{
	if(c == 'x')
	{
		if(N % 2 == 1)
			return 1;
		else 
			return -1;
	}
	else
	{		
		if(N % 2 == 1)
			return -1;
		else
			return 1;
	}
}
int main()
{

	std::clock_t    start;
	start = std::clock();

	vector<vector<int> > M(101);
	for(int i =0 ;i < int(M.size()) ;i++)
	{
		M[i] = vector<int>(101,0);
	}

	int x = 50; int y = 50;
	int Nx = 1; int Ny = 1;
//	int Sx = 1; int Sy = -1;
	int n = 2;
	M[x][y] = 1;
	cout << "starting while"<< endl;
	while(x < 101 && y < 101 && x>=0 && y>=0)
	{
		for(int i = 0;i<Nx;i++)
		{
			int sign = testN(n,'x');
			x+=sign;
			if(x>100)
				break;
			M[x][y] = n;
			n++;
			cout<< x << endl;
		}
		for(int i = 0;i<Ny;i++)
		{
			int sign = testN(n,'y');
			y+=sign;
			if(y>100)
				break;
			M[x][y] = n;
			n++;
		}
		Nx++;
		Ny++;

	}

	for(int i = 0; i <int( M.size()); i++)
	{
		for(int j = 0; j< int(M[x].size());j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}


	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}

