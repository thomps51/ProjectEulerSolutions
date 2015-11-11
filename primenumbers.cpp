#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
	int i=0;
	double number=2;
	while(i!=10001)
	{
		bool test2=true;
		for(int j=2;j<=sqrt(number);j++)
		{
			if(fmod(number,j)==0)
				test2=false;
		}
		if(test2)
		{
			printf("%f\n",number);
			i++;
		}
		if(i==10001)
			printf("%f",number);
		number++;
	}
}
