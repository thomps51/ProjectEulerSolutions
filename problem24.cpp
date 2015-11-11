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


int factorial(int n)
{
	  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
int main()
{
	//vector of 0...9 (N =10 numbers)
	//try 1mil -  N-1!
	//if >0, keep going
	//if <0, stop, use previous number
	vector<int> number;
	vector<int> finalNum;
	for(int i=0; i < 10;i++)
	{
		number.push_back(i);
//		cout<<number[i]<<endl;
	}
	int num = 1000000;
	while(num > 1)
	{
		// i is factorial
		for(int i = number.size()-1 ; i >=0 ;i--)
		{
//			cout << num << endl;
			int numberOfFac = 0;
			for(int j = 0; j < 10 ; j++)
			{
				int result = num - j*factorial(i);
//				cout<< result << endl;
				if(result<=0)
				{
					numberOfFac = j-1;
					break;
				}
			}
			
			num = num - numberOfFac*factorial(i);

			for(int j =0 ;j<number.size();j++)
			{
	                	cout << number[j];
			}
			cout<< endl;
//			cout << numberOfFac << endl;
			int erased = *(number.begin()+numberOfFac);
			vector<int>::iterator erasedbs = number.erase(number.begin() + numberOfFac);
//			cout << (erased) << endl;
			cout << numberOfFac << endl;
//			for(int j =0 ;j<number.size();j++)
//			{
//	                	cout << number[j];
//			}
//			cout<< endl;
//			cout<< number.size()<<endl;
			finalNum.push_back(erased);

		}
	//	cout << num << endl;
	}
	cout<< endl;
	for(int i =0 ;i<finalNum.size();i++)
		cout << finalNum[i];

	cout<< endl;
}

