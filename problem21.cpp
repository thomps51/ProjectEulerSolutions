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

int main()
{
	vector<vector<int> > sums(30000);
	int sumAmicable = 0;
	for(int i=0;i<10000;i++)
	{
		int sum=0;
		for(int j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				sum+=j;
				if(j != i/j && j!=1)
					sum+=i/j;
			}
		}

		// sum is sum of divisors, now check if it's divisors sum to i

		int sumsum=0;
		for(int j=1;j<=sqrt(sum);j++)
		{
			if(sum%j==0)
			{
				sumsum+=j;
				if(j != sum/j && j!=1)
                                        sumsum+=sum/j;
			}
		}
		if(sumsum == i && i!=sum)
		{
			sumAmicable+=i;
			printf("%i, %i\n",i, sum);
		}
	}
	printf("%i\n",sumAmicable);
}

