#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <map>
//#include <pair>
#include <random>
#include <ctime> // Needed for the true randomization
#include <cstdlib> 
using namespace std;


int main()
{
  // make a permutation
  auto sorter = [](const pair<int,string> & a, const pair<int,string> & b) {  return a.first < b.first; };

  vector<int> nV={1,2,3,4,5,6,7,8,9,10};

  std::sort(nV.begin(), nV.end());

  vector<string> solutions; 

  do {
    int sum1 = nV[0] + nV[1] + nV[2];
    int sum2 = nV[3] + nV[2] + nV[4];
    int sum3 = nV[5] + nV[4] + nV[6];
    int sum4 = nV[7] + nV[6] + nV[8];
    int sum5 = nV[9] + nV[8] + nV[1];
    if( sum1 == sum2 && sum2 == sum3 && sum3== sum4 && sum4==sum5 ) {
     
      vector<pair<int, string>> sets;
      
      sets.push_back(make_pair(nV[0], to_string(nV[1]) + to_string(nV[2])));
      sets.push_back(make_pair(nV[3], to_string(nV[2]) + to_string(nV[4])));
      sets.push_back(make_pair(nV[5], to_string(nV[4]) + to_string(nV[6])));
      sets.push_back(make_pair(nV[7], to_string(nV[6]) + to_string(nV[8])));
      sets.push_back(make_pair(nV[9], to_string(nV[8]) + to_string(nV[1])));
   
      int min = 11;
      int minI=0;
      for(int i=0; i < sets.size();i++) {
        if(sets[i].first < min) {
          min=sets[i].first;
          minI = i;
        }
      }


      string solution;
      for(int i = minI; i< minI+sets.size() ;i++) {
        solution+= to_string(sets[i%sets.size()].first) + sets[i%sets.size()].second;
      }
      
      // external nodes: 0, 3, 5, 7, 9
      
      //if(solution.length() == 16) {
        solutions.push_back(solution);
      //}
    }


  } while (std::next_permutation(nV.begin(),nV.end()));


  cout << "number of solutions: " << solutions.size()<<endl;
  // test it


  sort(solutions.begin(), solutions.end());

  for(auto str : solutions) {
    cout << str << endl;
  }
}

