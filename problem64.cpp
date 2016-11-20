#include <iostream> 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <ctime>
#include "common.h"
#include <regex>
#include <gmp.h>

using namespace std;

//testIfRepeating(vector<int>& testVec)
//{
//  static testWindow
//}


int main() {
  clock_t begin = clock();

  mpf_t prevTerm;
  mpf_t prevTermInSeq;
  mpf_t nextTerm;
  mpf_t nextTermInSeq;
  mpf_t temp;

  mpf_init2 (prevTerm, 2100);
  mpf_init2 (prevTermInSeq, 2100);
  mpf_init2 (nextTerm, 2100);
  mpf_init2 (nextTermInSeq, 2100);
  mpf_init2 (temp, 2100);

  int max_num = 10000;
  int testSequenceLength = 10;

  vector<int> aVec;
  int count = 0;
  for(int i = 2; i<= max_num ; i++)
  //for(int i = 135; i< 136 ; i++)
  {
    int sqRootInt       = sqrt(i);

    mpf_set_si(prevTerm,i);  // need to take sq root
    mpf_set_si(prevTermInSeq, sqRootInt );
    if( i == sqRootInt*sqRootInt) continue; // test if irrational
    
    mpf_set_si(prevTerm,i);  // need to take sq root
    mpf_sqrt_ui(prevTerm, i);
    
    mpf_set_si(prevTermInSeq, sqRootInt );
    // make a sequence 
    string sequence = "";
    
    int numRepeats = 3;
    bool repeatSeqFound = false;
    int delayCount = 0;
    vector<unsigned long> secondVec;
    while(!repeatSeqFound) {
      mpf_sub(nextTerm, prevTerm, prevTermInSeq);
      mpf_ui_div(nextTerm,1,nextTerm);
      
      mpf_floor(nextTermInSeq, nextTerm);
      
      unsigned long num = mpf_get_ui(nextTermInSeq);
      sequence += to_string(num) + ",";

      aVec.push_back(num);
      int delayNum = 10;
      if(aVec.size() < delayNum)
      {
      }
      else if(aVec.size() == delayNum) {
        secondVec.push_back( aVec[delayCount] );
      }
      else {
        delayCount++;
        secondVec.push_back(aVec[delayCount]);
      }
      int repeatLength = secondVec.size() / numRepeats;
      if( secondVec.size() != 0 && secondVec.size() % numRepeats  == 0)
      {
        int numberOfValues = secondVec.size() / numRepeats;
        auto it = secondVec.begin();
        static vector<vector<unsigned long>> testVec;
        
        for(int ii = 0; ii < numRepeats ;ii++) {
          vector<unsigned long> vec(it+(ii*numberOfValues), it+((ii+1)*numberOfValues));
          testVec.push_back(vec); 
        }
        
        repeatSeqFound=true;
        for(int ii = 0; ii< numRepeats-1; ii++)
        {
          for(int j = 0; j< testVec[0].size() ; j++)
          {
            if(testVec[ii][j] != testVec[ii+1][j])
            {
              repeatSeqFound = false;
              break;
            }
          }
          if(!repeatSeqFound) break;
        }
        if(repeatSeqFound) {
          if(repeatLength <= 3) {
            for( auto value : aVec)
            {
              if(std::find(testVec[0].begin(), testVec[0].end(), value) == testVec[0].end())
              {
                repeatSeqFound = false;
                break;
              }
            }
          }
          if( repeatSeqFound && (repeatLength) %2 ==1) {
            count++;
          }
        }
        testVec.clear();
      }
  



      mpf_set(prevTermInSeq, nextTermInSeq);
      mpf_set( prevTerm, nextTerm);

    }




    aVec.clear();
    secondVec.clear();
  }
  cout << "count: " << count << endl; 

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs*1000 << " ms"  << endl;
}

