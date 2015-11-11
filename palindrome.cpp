#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	for(double i=100;i<1000;i++)
	{
		for(double j=100;j<1000;j++)
		{
			int a=i*j;
			stringstream ss;
			ss << a;
			string str = ss.str();
			bool test=true;
			for(int i=0;i<3;i++)
			{
				if(str[i]==str[5-i])
				{
				}
				else
					test=false;
			}
			if(test==true)
				printf("%i\n",a);
		}
	}
}
