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
	int factors=0;
	int triangleN=1;
	while(factors<500)
	{
		factors=0;
		int number=0;
		for(int i=1;i<=triangleN;i++)
		{
			number+=i;
		}
//		printf("%i\n",number);
		
		for(int i=1;i<=sqrt(number);i++)
		{
			if(number%i==0)
				factors++;
		}
		factors*=2;
		if(factors>500)
			printf("%i\n",number);
		triangleN++;
	}
}
