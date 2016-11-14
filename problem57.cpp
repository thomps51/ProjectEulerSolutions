#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include "common.h"
#include "fraction.h"
using namespace std;  // since cin and cout are both in namespace std, this saves some text





int main() {
    //fraction one(1,1);
    //fraction two(2,1);
    //for(int i=2;i<=999;i++)
    //{
    //    fraction Value=(two+one/two);
    //    for(int j =0; j< i ;j++)
    //    {
    //        Value=one/Value;
    //        if(j != i-1) Value=two+Value;
    //        else         Value=one+Value;  
    //    }
    //    Value.Print();
    //    if(to_string(Value.num).length() != to_string(Value.denom).length())
    //        cout << "!" << endl;
    //}
    bool flag =true; // start with 8
    int group=8;
    int total=0;
    for(int i =1;i<=1000;i++)
    {
        if(flag)
        {
            group--;
            if(group==0)
            {
                flag=false;
                group=5;
                total++;
            }
        }
        else
        {
            group--;
            if(group==0)
            {
                flag=true;
                group=8;
                total++;
            }
        }
        
    }
    cout << total << endl;
}
