#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;  // since cin and cout are both in namespace std, this saves some text

bool isPalindrome(string s)
{
    for(int i =0; i < s.length()/2;i++)
    {
        if(s[i] != s[s.length()-1-i])
        {
            return false;
        }
    }
    return true;
}
string reverseString(string s)
{
    string reversedStr="";
    for(int i =0;i < s.length();i++)
    {
        reversedStr+=s[s.length()-1-i];
    }
    return reversedStr;
}
string addStrings(string s1, string s2)
{
    // these will always be the same length
    string addedString =""; 
    int carry = 0;
    //cout << "adding " << s1 << " and " << s2 << endl;
    for(int i =s1.length()-1;i >=0;i--)
    {
       int currPlace=int(s1[i]-'0')+int(s2[i]-'0')+carry;
       //cout << s1[i] << " + " << s2[i] << " = " << currPlace << endl;;
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
int main() {
    int NLych=0;
   for(int i =10; i< 10000; i++)
   {
        //cout << "Number is : " << i << endl;
        string numStr=to_string(i);
        int iterations=0;
        bool isLychrel=true;
        while(iterations<50)
        {
            string revNumStr=reverseString(numStr);

            numStr=addStrings(numStr,revNumStr);
            //cout << numStr<< endl;
            if(isPalindrome(numStr))
            {
                isLychrel=false;
                break;
            }
            iterations++; 
        }
        if (isLychrel)
        {
            cout << i << endl;
            NLych++;
        }
   }
   cout << NLych << endl;
}
