#include <iostream> 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <ctime>
#include "common.h"
#include "fractionLong.h"
#include <regex>
#include <gmpxx.h>
#include "problem64.cpp"

using namespace std;

fractionLong recursiveFrac(unsigned long int i, unsigned long int max_i, vector<unsigned long> sequence) {

  unsigned long term= sequence[i%sequence.size()]; 

  if (i == max_i) {
    return fractionLong(1,1) / ( fractionLong(term,1));
  }

  return fractionLong(1,1) / ( fractionLong(term,1) + recursiveFrac(i+1, max_i, sequence));
}

int main() {
  clock_t begin = clock();
  
  unsigned long int minD = 2;
  unsigned long int maxD = 1000; 
  vector<unsigned long> Ds;
  unsigned long int D =0;
  mpz_class temp1, temp2, temp3, temp4, temp5,maxX;
  
  
  for( int i =minD; i<=maxD; i++) {
    D=i;
    unsigned long sqRT = sqrt(D);
    if(sqRT*sqRT == D ) continue;
    Ds.push_back(i);
  }

  unordered_map<unsigned long, vector<unsigned long>> sequences = problem64();
 
  // Loop over Ds
  //  Loop over continued fractions looking for solution

  maxX=0;
  unsigned long maxOfD=0;
  for(int x = 0; x<Ds.size();x++) {
    D = Ds[x];
    cout <<"finding for D = " <<D << endl;
    vector<unsigned long> sequence = sequences[D];
    
    long unsigned int max_iter = 0;
    while(true) {
      unsigned long startingValue = sqrt(D);
      fractionLong startingFrac(startingValue,1);
      fractionLong endFrac = startingFrac + recursiveFrac(0, max_iter, sequence);

      temp1 = endFrac.num;    // x
      temp2 = endFrac.denom;  // y

      //cout << "checking " << temp1 << "/" << temp2 << endl;

      if(temp1*temp1 - D*temp2*temp2 == 1) {
        if(temp1 > maxX) {
          maxX = temp1;
          maxOfD = D;
        }
        //cout << "found!" << endl;
        break;
      }
      max_iter++;

    } 
  }

  cout << "max D is " << maxOfD << endl;
  cout << "max X is " << maxX << endl;
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs*1000 << " ms"  << endl;

  return 0;

  mpz_class x;  

  x=2;
 
  temp1 = x*x-1;

  while( true ) {
    
    mpz_mul(temp1.get_mpz_t(), x.get_mpz_t(),x.get_mpz_t());
    mpz_sub_ui(temp1.get_mpz_t(), temp1.get_mpz_t(), 1);
 
    // even x
    for(int i =0; i < Ds.size() ; i++ ) {
      D=Ds[i];

      if( ! mpz_divisible_ui_p(temp1.get_mpz_t(),D) ) { 
        continue; 
      }

      //if( !mpz_divisible_p(temp3.get_mpz_t(),D.get_mpz_t() ) && !mpz_divisible_p(temp4.get_mpz_t(),D.get_mpz_t())  ) continue;
     
      mpz_divexact_ui(temp2.get_mpz_t(), temp1.get_mpz_t(), D); 


      if(temp2 == 0) {
        continue;
      }
      if( ! mpz_perfect_square_p(temp2.get_mpz_t())  ) {
        continue;
      }

      //if( temp2*D != temp1)  continue;

      Ds.erase(Ds.begin() + i);
      i--;
      cout << Ds.size()<< " " << x << endl;
      if(Ds.size() == 1) {
        goto end;
      }
    }
    //temp2 = 2*x + 1;
    //x++;

    //mpz_add(temp1.get_mpz_t(), temp1.get_mpz_t(), temp2.get_mpz_t());

    mpz_add_ui(x.get_mpz_t(), x.get_mpz_t(),1) ;


    //temp1 = x*x - 1;
    //// odd x
    //for(int i =0; i < Ds.size() ; i++ ) {
    //  D=Ds[i];

    //  if( ! mpz_divisible_p(temp1.get_mpz_t(),D.get_mpz_t()) ) { 
    //    continue; 
    //  }

    //  mpz_divexact(temp2.get_mpz_t(), temp1.get_mpz_t(), D.get_mpz_t()); 


    //  if(temp2 == 0) {
    //    continue;
    //  }
    //  if( ! mpz_perfect_square_p(temp2.get_mpz_t())  ) {
    //    continue;
    //  }

    //  //if( temp2*D != temp1)  continue;

    //  Ds.erase(Ds.begin() + i);
    //  i--;
    //  cout << Ds.size()<< " " << x << endl;
    //}
    //x++;
  
  
  
  }

end:
  cout << Ds[0] << endl;


  //clock_t end = clock();
  //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  //cout << elapsed_secs*1000 << " ms"  << endl;
}

