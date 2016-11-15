#include <iostream> 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;  
static vector<string> answer;
void recursiveGetSequence(  vector<string> possSeq, 
                            unordered_set<int> coveredTypes, 
                            string currStr, 
                            int currType,
                            unordered_map< int , unordered_map< string, vector< pair<string,int>>>>& map)
{
  if( coveredTypes.count(currType) == 1 ) return;
  if(map[currType].count(currStr) == 0 ) return;
  if( possSeq.size() == 5)
  {
    for( auto pair : map[currType][currStr])
    {
      if( pair.first == possSeq[0])
      {
        possSeq.push_back(currStr);
        answer = possSeq;
        return;
      }
    }
    return;
  }
  possSeq.push_back(currStr);
  coveredTypes.insert(currType);

  for( auto& possibleNext : map[currType][currStr] )
  {
    recursiveGetSequence(possSeq, coveredTypes, possibleNext.first, possibleNext.second, map);
  }
}

int main() {
  clock_t begin = clock();
  // create 2d vector of 1st D = number type (tri, sq, etc..)
  //   2nd D = 4 digit numbers of that type
  vector<vector<string>> numbers(6);
  vector<int> currNums(6);
  for(int i =1 ; i<10000;i++)
  {
    currNums[0] = i*(i+1) / 2;
    currNums[1] = i*i;
    currNums[2] = i*(3*i - 1) / 2;
    currNums[3] = i*(2*i+1);
    currNums[4] = i*(5*i-3)/2;
    currNums[5] = i*(3*i-2);

    for(int j = 0; j<currNums.size();j++)
    {
      int currNum = currNums[j];
      string currNumStr = to_string(currNum);
      if(currNumStr.length() == 4)
      {
        numbers[j].push_back(currNumStr);
      }
    }
  }


  // create a map of maps of vectors

  // map of ints(one for tri, sq, etc) to
  //    map of string(number) to vector of strings (numbers that 
  //    the first 2 digits match the last two of the key)
  unordered_map< int , unordered_map< string, vector< pair<string,int>>>> map;

  // loop over tri, sq, etc...
  for(int i =0; i<numbers.size() ; i++)
  {
    // loop over values in tri, sq, etc set
    for(int j =0 ; j<numbers.at(i).size(); j++)
    {
      string currNum = numbers.at(i).at(j);
      // loop over values in other sets
      for(int k = 0; k<numbers.size() ;k++)
      {
        if (i == k) continue;
        for(int l = 0; l< numbers.at(k).size() ; l++)
        {
          string compNum = numbers.at(k).at(l); 
          if( currNum[2] == compNum[0] && currNum[3] == compNum[1])
          {
            map[i][currNum].push_back(make_pair(compNum,k));
          }
        }
      }
    }
  }

  // loop over possible starting values
  // recursively try to make a sequence of 6
  for(int i =0; i< map.size() ; i++)
  {
    for(auto& pair : map[i])
    {
      vector<string> possibleSequence;
      unordered_set<int> coveredTypes;
      string startingValue =  pair.first;
      recursiveGetSequence(possibleSequence, coveredTypes, startingValue, i, map);
      if(answer.size() == 6) goto end;
    }
  }

  end:
  int sum = 0;
  for( auto value: answer)
  {
    cout << value << " ";
    sum += stoi(value);
  }
  cout << endl;

  cout << sum << endl;

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs*1000 << " ms"  << endl;
}

