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
  clock_t begin = clock();
  std::fstream myfile("numbers2.txt", std::ios_base::in);
  //std::fstream myfile("numbers.txt", std::ios_base::in);
  
  int numRows = 100;
  //int numRows = 15;

  int a;
  vector<vector<int> > numbers(numRows);
  for(int i=0;i<numRows;i++) {
    numbers[i]= vector<int>(i+1);
  }
	int prevColumn=0;
	int row=0;
  int i=0;
  while (myfile >> a)
  {
		int column = .5*(sqrt(8*i+1)-1);
		if(abs(prevColumn-column)==1)
		{
			row=0;
		}
    numbers[column][row]=a;
    i++;
		prevColumn=column;
		row++;
  }
  //for(int i=0;i<numRows;i++)
  //{
  //  //cout << i << " " << endl;    
  //  for(int j=0;j<=i;j++)
  //  {
  //    //cout << "i="<<i << " j=" << j << endl;    
  //    printf("%i ",numbers[i][j]);
  //  }
  //  printf("\n");
  //}

  // start from end-1, collapse end into end -1

  for(int i = numRows-2; i>=0 ; i--) {

    for(int j = 0 ; j < numbers[i].size() ; j++) {
      int left  = numbers[i+1][j];
      int right = numbers[i+1][j+1];

      if(left > right) {
        numbers[i][j] += left;
      }
      else {
        numbers[i][j] += right;
      }
    }

  }
  cout << numbers[0][0]<< endl;;
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs*1000 << " ms"  << endl;
}

