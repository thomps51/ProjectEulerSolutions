#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	std::fstream myfile("problem11.txt", std::ios_base::in);

	int a;
	int i=0;
	vector<vector<int> > numbers(20);
	for(int i=0;i<20;i++)
		numbers[i]= vector<int>(20);
	numbers[0][0]=1;
 	while (myfile >> a)
 	{
		numbers[(i/20)][i%20]=a;	
//		printf("%i ", a);
		i++;
    	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			printf("%i ",numbers[i][j]);
		}
		printf("\n");
	}

	// across
	int maxAcross=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<17;j++)
		{
			int current=numbers[i][j]*numbers[i][j+1]*numbers[i][j+2]*numbers[i][j+3];
			if(current>maxAcross)
				maxAcross=current;
		}
	}

	// down
	int maxDown=0;

	for(int i=0;i<17;i++)
        {
                for(int j=0;j<20;j++)
                {
                        int current=numbers[i][j]*numbers[i+1][j]*numbers[i+2][j]*numbers[i+3][j];
                        if(current>maxDown)
                                maxDown=current;
                }
        }	
	// diagonal down right
	int maxDiag1=0;
	for(int i=0;i<17;i++)
        {
                for(int j=0;j<17;j++)
                {
                        int current=numbers[i][j]*numbers[i+1][j+1]*numbers[i+2][j+2]*numbers[i+3][j+3];
                        if(current>maxDiag1)
                                maxDiag1=current;
                }
        }

	// diagonal up right

	int maxDiag2=0;
        for(int i=3;i<20;i++)
        {
                for(int j=0;j<17;j++)
                {
                        int current=numbers[i][j]*numbers[i-1][j+1]*numbers[i-2][j+2]*numbers[i-3][j+3];
                        if(current>maxDiag2)
                                maxDiag2=current;
                }
        }
	printf("%i, %i, %i, %i", maxAcross,maxDown,maxDiag1,maxDiag2);
}
