#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
//#include <ostream>
using namespace std;
class fraction{
    public:  
    //inline fraction operator+=(const fraction& rhs);
    //inline fraction operator*=(fraction lhs, const fraction& rhs);
    //inline fraction operator/=(fraction lhs, const fraction& rhs);
    
    long long num;
    long long denom;
    fraction(long long numer, long long denomer);
    void simplify();
    long long getLCM(long long num1, long long num2);
    long long getGCDivis(long long num1, long long num2);
    inline fraction operator+=(const fraction& rhs)
    {
        long long LCM = getLCM(denom,rhs.denom);
        //cout << "LCM: " << LCM << endl;
        long long numSum= (LCM / denom) * num+ (LCM / rhs.denom) * rhs.num;
        //cout << "numSum: " << numSum << endl; 
        num=numSum;
        denom=LCM;
        simplify();
        return *this;
    }
    inline fraction operator*=(const fraction& rhs)
    {
        num=num*rhs.num;
        denom=denom*rhs.denom;
        simplify();
        return *this;
    }
    inline fraction operator/=(const fraction& rhs)
    {
        num=num*rhs.denom;
        denom=denom*rhs.num;
        simplify();
        return *this;
    }
    void Print()
    {
        cout << num << "/" << denom << endl;    
    }
};
inline fraction operator+(fraction lhs, const fraction& rhs)
{
    lhs+=rhs;
    return lhs;
}
inline fraction operator*(fraction lhs, const fraction& rhs)
{
    lhs*=rhs;
    return lhs;
}
inline fraction operator/(fraction lhs, const fraction& rhs)
{
    lhs/=rhs;
    return lhs;
}
