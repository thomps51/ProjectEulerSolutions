#include <iostream> 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <ctime>
#include "common.h"
#include "fractionLong.h"
#include <regex>

using namespace std;

fractionLong recursiveFrac(int i, int max_i, int k) {
  int mod = i%3;
  int term = 0;
  if(mod == 0 || mod == 2) {
    term = 1;
  }
  else {
    term = 2 * k;
    k++;
  }
  if (i == max_i) {
    return fractionLong(1,1) / ( fractionLong(term,1));
  }
  
  return fractionLong(1,1) / ( fractionLong(term,1) + recursiveFrac(i+1, max_i, k));
}


int main() {
  clock_t begin = clock();

  fractionLong startingFrac(2,1);

  fractionLong endFrac = startingFrac + recursiveFrac(0, 98, 1);

  string numString = endFrac.getNumString();

  cout << numString << endl;

  int sum=0;
  for(unsigned int i =0; i<numString.length() ;i++) {
    sum += int( numString[i] - '0' );
  }
  cout << sum << endl;

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs*1000 << " ms"  << endl;
}

