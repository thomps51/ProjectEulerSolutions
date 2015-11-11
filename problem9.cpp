#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
	for(double a=1;a<500;a++)
	{
		for(double b=1;b<500;b++)
		{
			double c=sqrt(a*a+b*b);
			if(a+b+c==1000)
				printf("%f,%f,%f,%f\n",a*b*c,a,b,c);
		}
	}
}
