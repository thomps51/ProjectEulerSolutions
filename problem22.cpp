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

bool stringCompare( const string &left, const string &right ){
   for( string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
      if( tolower( *lit ) < tolower( *rit ) )
         return true;
      else if( tolower( *lit ) > tolower( *rit ) )
         return false;
   if( left.size() < right.size() )
      return true;
   return false;
}

int main()
{
	std::ifstream myfile("names.txt", std::ios_base::in);
	string a;
	vector<string> names;

	getline(myfile,a);

	bool isQuote = false;
	int nameIndex=-1;
	int quoteIndex=0;
	for(int i = 0;i<a.length();i++)
	{
		if(a[i] == '"')
		{
			isQuote = !isQuote;
			quoteIndex++;
			if(quoteIndex%2==1)
			{
				nameIndex++;
				names.push_back(string());
			}
		}
		if(isQuote && a[i] != '"')
		{
			names[nameIndex] += a[i];
		}
	}

	sort(names.begin(), names.end(),stringCompare);

	for(int i =0;i<names.size();i++)
		cout<<names[i]<<endl;

	int sum = 0;
	for(int i=0;i<names.size();i++)
	{
		int wordScore=0;
		for(int j =0;j<names[i].length();j++)
		{
			wordScore+=names[i][j] - 'A' + 1;
		}
		sum+= wordScore*(i+1);
	}
	cout << sum <<endl;

}

