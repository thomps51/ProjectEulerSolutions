#ifndef COMMON_H
#define COMMON_H
#include <cmath>
using namespace std;

bool primeTest(double n) {
    if(n < 0)
        return false;
    
    for(int j = 2;j<=sqrt(n);j++)
    {
        if(fmod(n,j)==0)
        {
            cout << n/j << endl;
            return false;
        }
    }
    return true;
}
bool primeTest(int n) {
    if(n < 0)
        return false;
 
    if(n%2 == 0)
    {
      return false;
    }

    for(int j = 3; j*j <= n ;j+=2)
    {
        if( n%j==0)
        {
            return false;
        }
    }
    return true;
}
bool primeTest(unsigned long int n) {
    if(n%2 == 0)
    {
      return false;
    }

    for(unsigned long int j = 3; j*j <= n ;j+=2)
    {
        if( n%j==0)
        {
            return false;
        }
    }
    return true;
}
bool testIfCube (unsigned long int n) {
  unsigned long int root = round(cbrt(n));
  return root*root*root == n;
}
string reverseString(string s) {
    string reversedStr="";
    for(int i =0;i < s.length();i++)
    {
        reversedStr+=s[s.length()-1-i];
    }
    return reversedStr;
}
bool isPalindrome(string s) {
    for(int i =0; i < s.length()/2;i++)
    {
        if(s[i] != s[s.length()-1-i])
        {
            return false;
        }
    }
    return true;
}
string addStrings(string s1, string s2) {
    // make the strings the same length
    if ( s1.length() != s2.length())
    {
        int difference = abs(int(s1.length()) - int(s2.length()));
        string zerosString="";
        for(int i = 0; i < difference;i++)
        {
            zerosString+="0";
        }
        if (s1.length() > s2.length()) s2=zerosString+s2;
        else                           s1=zerosString+s1;
    }

    string addedString ="";
    int carry = 0;
    for(int i =s1.length()-1;i >=0;i--)
    {
       int currPlace=int(s1[i]-'0')+int(s2[i]-'0')+carry;
       string currPlaceStr="";
       currPlaceStr=to_string(currPlace);
       if(currPlace>9)
       {
            carry=1;
            currPlaceStr=currPlaceStr[1];
       }
       else {
        carry=0;
       }
       addedString=currPlaceStr+addedString;
    }
    if(carry !=0) addedString=to_string(carry)+addedString;
    return addedString;
}
string stringMultiply(string s1, string s2) {
    int carry=0;
    int currTensPow=0;
    string runningTotal="";
    for(int i = s2.length()-1 ; i>=0; i--)
    {
        string digitMultiply="";
        for(int j =0; j<currTensPow;j++)
        {
            digitMultiply="0"+digitMultiply;
        }
        carry=0;
        for(int j = s1.length()-1;j>=0 ;j--)
        {
            int currPlace=int(s2[i]-'0') * int(s1[j]-'0') + carry;
            carry=currPlace/10;
            int digit=currPlace % 10;
            digitMultiply=to_string(digit)+digitMultiply;
        }
        if(carry != 0) digitMultiply = to_string(carry)+digitMultiply;
        runningTotal=addStrings(runningTotal,digitMultiply);

        currTensPow++;
    }
    return runningTotal;
}
string stringPow(string base, string pow) {
    string total = base;
    for(int i =1; i< stoi(pow);i++)
    {
        total=stringMultiply(total,base);
    }
    return total;
}

#endif /**COMMON_H**/
