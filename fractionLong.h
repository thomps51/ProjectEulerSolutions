#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
//#include <gmp.h>
#include <gmpxx.h>
using namespace std;
class fractionLong {
    public:  
    
    //mpz_t num;
    //mpz_t denom;

    mpz_class num;
    mpz_class denom;

    fractionLong(long numer, long denomer) {
      num = numer;
      denom = denomer;
      simplify();   
    }
    void simplify() {
      mpz_t divisor;
      mpz_init(divisor);
      mpz_gcd(divisor, num.get_mpz_t() ,denom.get_mpz_t());

      mpz_divexact(num.get_mpz_t(), num.get_mpz_t(), divisor);
      mpz_divexact(denom.get_mpz_t(), denom.get_mpz_t(), divisor);
    }
    inline fractionLong operator+=(const fractionLong& rhs) {
        mpz_t LCM;
        mpz_init(LCM);
        mpz_lcm(LCM, denom.get_mpz_t(), rhs.denom.get_mpz_t());
       
        mpz_t temp1;
        mpz_init(temp1);
        mpz_divexact(temp1, LCM, denom.get_mpz_t());
        mpz_mul(temp1, temp1, num.get_mpz_t());
        
        mpz_t temp2;
        mpz_init(temp2);
        mpz_divexact(temp2, LCM, rhs.denom.get_mpz_t());
        mpz_mul(temp2, temp2, rhs.num.get_mpz_t());

        mpz_add(num.get_mpz_t(), temp1, temp2);
        mpz_set(denom.get_mpz_t(), LCM);

        simplify();
        return *this;
    }
    inline fractionLong operator*=(const fractionLong& rhs) {
        mpz_mul(num.get_mpz_t(), num.get_mpz_t(), rhs.num.get_mpz_t());
        mpz_mul(denom.get_mpz_t(), denom.get_mpz_t(), rhs.denom.get_mpz_t());
        simplify();
        return *this;
    }
    inline fractionLong operator/=(const fractionLong& rhs) {
        mpz_mul(num.get_mpz_t(), num.get_mpz_t(), rhs.denom.get_mpz_t());
        mpz_mul(denom.get_mpz_t(), denom.get_mpz_t(), rhs.num.get_mpz_t());
        simplify();
        return *this;
    }
    void Print() {

        char* numStr   = mpz_get_str(NULL, 10, num.get_mpz_t());
        char* denomStr = mpz_get_str(NULL, 10, denom.get_mpz_t());

        cout << numStr << "/" << denomStr << endl;    
    }
    string getNumString() {
      char* numStr   = mpz_get_str(NULL, 10, num.get_mpz_t());
      return string(numStr);
    }
};
inline fractionLong operator+(fractionLong lhs, const fractionLong& rhs) {
    lhs+=rhs;
    return lhs;
}
inline fractionLong operator*(fractionLong lhs, const fractionLong& rhs) {
    lhs*=rhs;
    return lhs;
}
inline fractionLong operator/(fractionLong lhs, const fractionLong& rhs) {
    lhs/=rhs;
    return lhs;
}
