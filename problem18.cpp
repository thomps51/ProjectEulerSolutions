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

int findMax(vector<vector<int> > & numbers, int row, int column)
{
	if(row == 14)
		return numbers[row][column];
	int max1 = numbers[row][column]+findMax(numbers,row+1,column);
	int max2 = numbers[row][column]+findMax(numbers,row+1,column+1);
	return max(max1,max2);
}

int main()
{
        std::fstream myfile("numbers.txt", std::ios_base::in);

        int a;
        int i=0;
        vector<vector<int> > numbers(15);
        for(int i=0;i<15;i++)
                numbers[i]= vector<int>(i+1);

	int prevColumn=0;
	int row=0;
        while (myfile >> a)
        {
		
		int column = .5*(sqrt(8*i+1)-1);
		if(abs(prevColumn-column)==1)
		{
			row=0;
		}
                numbers[column][row]=a;
                i++;
		prevColumn=column;
		row++;
        }
        for(int i=0;i<15;i++)
        {
                for(int j=0;j<=i;j++)
                {
                        printf("%i ",numbers[i][j]);
                }
                printf("\n");
        }
	int max= findMax(numbers,0,0);	
	
	printf("%i\n",max);	
}

