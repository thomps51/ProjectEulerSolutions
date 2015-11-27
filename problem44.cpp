#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <omp.h>
using namespace std;
int main()
{
    int N =3000;
   
    #pragma omp parallel for 
    for(int ni=1;ni<N;ni++)
    {
        for(int nj=ni;nj<N;nj++)
        {
            double sum = 3*ni*ni -ni + 3*nj*nj-ni;
            double diff = 3*nj*nj -nj - 3*ni*ni+ni;
            double quadSumm = (1 + sqrt(1+24*sum)) / 12;
            double quadDiff = (1 + sqrt(1+24*diff)) / 12;
            if(fmod(quadSumm,1) == 0 && fmod(quadDiff,1)==0)
                cout << "got one" << endl;
        }
    
    

    }


}


