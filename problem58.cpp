#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include "common.h"
#include "fraction.h"
using namespace std;  // since cin and cout are both in namespace std, this saves some text



/**
Starting from 1, the diagonals are as follows:

3 13 31     57
5 17 37     65
7 21 43     73
9 25 49     81


**/
int ratio =100;
int main() {
    int i=1;
    int increment=2;
    int value=1;

    int primeCount=0;
    int totalCount=1;
    while(true)
    {
        int sideLength = 2*i+1;
        for(int j =0; j<4;j++)
        {
            value += increment;
            if( j != 3 && primeTest(value))
            {
                primeCount++;
            }
            totalCount++; 
        }
        // then test ratio
        ratio=(100*primeCount)/totalCount;
        
        if (ratio < 10)
        {
            cout << "side length: " << sideLength << " ratio: " << ratio << endl; 
            break;
        }

        increment += 2;
        i++; 
    }

}
