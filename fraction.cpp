#include "fraction.h"
fraction::fraction(long long numer, long long denomer)
{
    num=numer;
    denom=denomer;
    simplify();
}

void getPrimeFactorsRecursive(long long number, vector<long long> & accumulator)
{
    bool prime = true;
    for(long long i =2;i<=sqrt(number);i++)
    {
        if( number % i == 0)
        {
            getPrimeFactorsRecursive(i,accumulator);
            getPrimeFactorsRecursive(number/i,accumulator);
            prime=false;
            break;
        }
    }
    if(prime) accumulator.push_back(number);
}
vector<long long> getPrimeFactors(long long number)
{
    vector<long long> factors;
    getPrimeFactorsRecursive(number,factors);
    return factors;
}

long long fraction::getLCM(long long num1, long long num2)
{
    vector<long long> num1Factors=getPrimeFactors(num1);
    vector<long long> num2Factors=getPrimeFactors(num2);
    vector<long long> lcm_parts;
    for(long long i=0; i< num1Factors.size();i++)
    {
        vector <long long>::iterator It =std::find(num2Factors.begin(),num2Factors.end(),num1Factors[i]);
        if(It != num2Factors.end())
        {
            num2Factors.erase(It);
        }
        lcm_parts.push_back(num1Factors[i]);

    }
    lcm_parts.insert(lcm_parts.end(),num2Factors.begin(),num2Factors.end());
    long long LCM=1;
    for(long long i =0; i< lcm_parts.size();i++)
    {
       LCM *= lcm_parts[i];
    }
    return LCM;
}

long long fraction::getGCDivis(long long num1, long long num2)
{
    vector<long long> num1Factors=getPrimeFactors(num1);
    vector<long long> num2Factors=getPrimeFactors(num2);
    vector<long long> commonFactors;
    for(long long i = 0; i< num1Factors.size();i++)
    {
        vector <long long>::iterator It =std::find(num2Factors.begin(),num2Factors.end(),num1Factors[i]);
        if(It != num2Factors.end())
        {
            commonFactors.push_back(num1Factors[i]);
            num2Factors.erase(It);
        }
    }
    long long GCD=1;
    for(long long i =0;i<commonFactors.size();i++)
    {
        GCD *= commonFactors[i];
    }
    return GCD;
}

void fraction::simplify()
{
    long long divisor=getGCDivis(num,denom);
    num=num/divisor;
    denom=denom/divisor;
}
//inline fraction fraction::operator+=(const fraction& rhs)
//{
//    long long LCM = getLCM(denom,rhs.denom);
//    long long numSum= (LCM / denom) * num+ (LCM / rhs.denom) * rhs.num;
//    num=numSum;
//    denom=LCM;
//    simplify();
//    return *this;
//}
//inline fraction operator+(fraction lhs, const fraction& rhs)
//{
//    long long LCM = getLCM(lhs.denom,rhs.denom);
//    long long numSum= (LCM / lhs.denom) * lhs.num+ (LCM / rhs.denom) * rhs.num;
//    return fraction(numSum,LCM);
//}









