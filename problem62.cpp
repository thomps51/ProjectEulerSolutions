#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include "common.h"
#include "fraction.h"
using namespace std;  



/**


**/

int main() {
  unsigned long int maxNum = 15000;
  
  // map of size of string to vector of cubes
  unordered_map<unsigned long int, vector<string>> sizeToCubes;
  unsigned long int maxLength = 13;
  for(unsigned long int i = 1; i< maxNum;i++)
  {
    string cubeStr = to_string(i*i*i);
    unsigned long int length = cubeStr.length();
    sizeToCubes[length].push_back(cubeStr);
    if(length > maxLength) maxLength = length;
  }
  for(unsigned long int i = 1; i< maxLength;i++)
  {
    vector<string> nums = sizeToCubes[i];
    
    for(unsigned int i1 = 0; i1 < nums.size() ; i1++)
    {
      vector<string> permutations;
      for(unsigned int i2 = i1+1; i2 < nums.size();i2++)
      {
        string num1 = nums[i1];
        string num2 = nums[i2];
        if( is_permutation (num1.begin(), num1.end(), num2.begin()) )
        {
          permutations.push_back(num2);
        }
      }
      if(permutations.size() == 4)
      {

        cout << "FOUND!" << endl;
        cout << "Number is " << nums[i1] << endl;
        for(auto value : permutations)
        {
          cout << value << " ";
        }
        cout << endl;
      }
    }
  }

}
