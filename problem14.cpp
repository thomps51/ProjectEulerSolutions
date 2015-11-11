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
	int maxSteps=0;
	double maxNumber=0;
	for(int i=1;i<1000000;i++)
	{
		int steps=0;
		double number=i;
		while(number!=1)
		{
			if(fmod(number,2)==0)
				number=number/2;
			else
				number=3*number+1;
			steps++;
			if(i==113383)
				printf("%f\n",number);
			if(number<0)
				break;
		}
		if(number<0)
			break;
		if(steps>maxSteps)
		{
			maxSteps=steps;
			maxNumber=i;
		}
		printf("%i\n",i);
	}
	printf("%f",maxNumber);
	
}
