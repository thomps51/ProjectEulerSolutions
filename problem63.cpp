#include <iostream> 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <ctime>
#include "common.h"

using namespace std;
int main() {
  clock_t begin = clock();

  int pow_limit = 100;
  int count =0;
  for(int i=1 ; i<10 ; i++)
  {
    // loop over powers
    for(int pow = 1 ; pow < pow_limit ; pow++)
    {
      std::string ans = stringPow( to_string(i), to_string(pow));
      if( ans.length() == pow )
      {
        count++;
      }
    }

  }
  cout << "count: " << count << endl;


  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs*1000 << " ms"  << endl;
}

