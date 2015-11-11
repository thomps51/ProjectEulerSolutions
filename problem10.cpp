#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
        double number=2;
	double sum=0;
        while(number<2000000)
        {
                bool test2=true;
                for(int j=2;j<=sqrt(number);j++)
                {
                        if(fmod(number,j)==0)
                                test2=false;
                }
                if(test2)
                {
                    sum+=number;    
                }
                number++;
        }
	printf("%f\n",sum);
}
