#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include "common.h"
#include "fraction.h"
using namespace std;  // since cin and cout are both in namespace std, this saves some text



/**


**/
bool testCat(int x, int y)
{
  string s1 = to_string( x );
  string s2 = to_string( y );
  
  string sComb1 = s1 +  s2;
  string sComb2 = s2 +  s1;
  int combined1 = stoi(sComb1);
  int combined2 = stoi(sComb2);
  
  if ( !primeTest(combined1) || !primeTest(combined2) ) 
  {
    return false;
  }
  return true;
}

std::unordered_map<int, vector<int>> makeMap(vector<int>& inputs)
{
  std::unordered_map<int,vector<int>> map;
  for(int i =0; i<inputs.size() ; i++)
  {
    for(int j=i+1;j<inputs.size();j++)
    {
      if(testCat(inputs[i],inputs[j]))
      {
        map[inputs[i]].push_back(inputs[j]); 
      }
    }
  }
  return map;
}

int main() {
    int num=2;
    vector<int> primeSet;
    while(num < 20000)
    {
        num++;
        if( ! primeTest(num) ) continue;
        primeSet.push_back(num);
    }
    std::unordered_map<int, vector<int>> map = makeMap(primeSet);
    
    int bestSum = INT_MAX;
    for(int i = 0 ; i< primeSet.size() ; i++)
    {
      vector<int> currNum = map[primeSet[i]];
     
      if(currNum.size() == 0) continue;
      for(int j = 0; j< currNum.size(); j++)
      {
        int num2 = currNum[j];
        for(int k =j+1; k<currNum.size(); k++)
        {
          int num3 = currNum[k];
          if(std::find(map[num2].begin(), map[num2].end(),num3) == map[num2].end()) continue;
          for(int l =k+1;l<currNum.size();l++)
          {
            int num4 = currNum[l];
            if(std::find(map[num2].begin(), map[num2].end(),num4) == map[num2].end()) continue;
            if(std::find(map[num3].begin(), map[num3].end(),num4) == map[num3].end()) continue;
            for(int m=l+1;m<currNum.size();m++)
            {
              int num5 = currNum[m];
              if(std::find(map[num2].begin(), map[num2].end(),num5) == map[num2].end()) continue;
              if(std::find(map[num3].begin(), map[num3].end(),num5) == map[num3].end()) continue;
              if(std::find(map[num4].begin(), map[num4].end(),num5) == map[num4].end()) continue;

              int sum = primeSet[i] +num2 +num3 + num4 + num5;
              cout << "sum: " << sum <<endl;
              if(sum < bestSum)
              {
                cout << primeSet[i] << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;;
                bestSum=sum;
                cout << "bestSum:" <<bestSum<< endl;
              }
              
            }
          }
        }
      }
    }
    cout << bestSum << endl;



}
