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
	vector<int> numberList(28123);
	for(int i=0;i<numberList.size();i++)
	{
		numberList[i] = i+1;
	}
	vector<int> notAbun;
	vector<int> abun;
	cout << "finding abundant numbers" << endl;
	for(int i=0;i<numberList.size();i++)
	{
		int number = numberList[i];
		// find proper divisors
		vector<int> divisors;
//		cout <<"number is: " <<number << endl;
		for(int j = 1;j < number; j++)
		{
			if(number%j == 0)
			{
				divisors.push_back(j);
//				cout << j << endl;
			}
		}
		int divSum = 0;
		for(int j = 0;j<divisors.size();j++)
		{
			divSum += divisors[j];
		}
		
		if(divSum > number)
		{
			abun.push_back(number);
		}

		if(number % 1000 == 0)
			cout << number << endl;

	}
// now have a list off all abundant number up to n
/*	vector<int> notAbunSum;
	cout << "finding numbers not the sum of 2 abundant numbers" << endl;
	for(int i = 0; i<numberList.size() ; i++)
	{
		int number = numberList[i];
		if(number %1000 == 0)
			cout << number << endl;
		if( number % 2 == 0 && number > 46)
			continue;
		if( number % 2 == 1)
		{
//			notAbunSum.push_back(number);
//			continue;
		}

		bool abunSum = false ;
		for(int j = 0; j<abun.size();j++)
		{
			int numberMabun = number - abun[j];
			if(numberMabun<0)
				break;
			for(int k = 0; k<abun.size();k++)
			{
				int numberMabun2 = numberMabun - abun[k];
				if(numberMabun2 == 0)
				{
					abunSum = true;
					continue;
//					cout << number << endl;
				}
			}
			if(abunSum)
				continue;
		}
		if(!abunSum)
		{
			notAbunSum.push_back(number);
//			cout << number << endl;
		}

	}
	*/
	
	// make all possible sums of abundant numbers
	vector<bool> abunSums(28124);
	for(int i = 0;i<abun.size();i++)
	{
 		for(int j=0;j<abun.size();j++)
		{
			if(abun[i]+abun[j] > 28123)
				continue;
			abunSums[abun[i]+abun[j]]=true;
		}
	}	
	int sum = 0;
	for(int i = 0;i<abunSums.size();i++)
	{
		if(abunSums[i] == false)
			sum+=i;
	}
	cout << sum << endl;
//	int sum = 0;
//	for(int i=0; i<notAbunSum.size();i++)
//		sum+=notAbunSum[i];
//	cout << sum << endl;
}

