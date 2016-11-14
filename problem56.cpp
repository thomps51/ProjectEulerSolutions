#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;  // since cin and cout are both in namespace std, this saves some text

string addStrings(string s1, string s2)
{
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
string stringMultiply(string s1, string s2)
{
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
        //cout << "digitMultiply: "<< digitMultiply<< endl;
        carry=0;
        for(int j = s1.length()-1;j>=0 ;j--)
        {
            int currPlace=int(s2[i]-'0') * int(s1[j]-'0') + carry;
            //cout << "currPlace: " <<currPlace << endl;
            carry=currPlace/10;
            //cout <<  "carry: " << carry << endl;
            int digit=currPlace % 10;
            //cout << "digit: " <<digit << endl;
            //cout << "digitMultiply: " << digitMultiply << endl;
            digitMultiply=to_string(digit)+digitMultiply;
            //cout << "digitMultiply: " << digitMultiply << endl;
        }
        //cout <<digitMultiply << endl; 
        if(carry != 0) digitMultiply = to_string(carry)+digitMultiply;
        //cout <<digitMultiply << endl; 
        runningTotal=addStrings(runningTotal,digitMultiply);
        
        currTensPow++;
    }
    return runningTotal;
}

string stringPow(string base, string pow)
{
    string total = base;
    for(int i =1; i< stoi(pow);i++)
    {
        total=stringMultiply(total,base);
    }
    return total;
}

long sumDigits(string s)
{
    long sum=0;
    for(int i =0; i< s.length();i++)
    {
        sum+=int(s[i] - '0');
    }
    return sum;
}

int main() {
    //cout << stringMultiply("525","72") << endl;
    cout << "Final Answer: " <<stringPow("15","15") << endl;

    int maxSum=0;
    for(int a =1; a<100;a++)
    {
        for(int b =1;b<100;b++)
        {
            string answer=stringPow(to_string(a),to_string(b));
            long sum = sumDigits(answer);
            if(sum>maxSum)
            {
                cout << "Found new max: " << sum << endl;
                maxSum=sum;
            }
        }
    }
    cout << maxSum << endl;
}
