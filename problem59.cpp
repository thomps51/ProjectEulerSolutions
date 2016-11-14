#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include "common.h"
#include "fraction.h"
#include "longString.h"
using namespace std;  // since cin and cout are both in namespace std, this saves some text



/**


**/

int main() {
    std::string to_split = testString;
    
    
    std::vector<std::string> array;
    std::size_t pos = 0, found;
    while((found = to_split.find_first_of(',', pos)) != std::string::npos) {
        array.push_back(to_split.substr(pos, found - pos));
        pos = found+1;
    }
    array.push_back(to_split.substr(pos));    



    for(int i=0;i<26;i++)
    {
        char char1 = 'a' + i;
        for(int j=0;j<26;j++)
        {
            char char2 = 'a' + j;
            for(int k=0;k<26;k++)
            {
                char char3 = 'a' +k;
                int currKey=1;
                deque<char> slidingWindow;
                bool theTest =false;
                bool andTest =false;
                bool notTest =false;
                vector<char> decryptedMessage;
                for(int ii =0; ii<array.size();ii++)
                {
                    char currChar = stoi(array[ii]);
                    char decryptedChar = 'a';
                    if (currKey == 1)
                    {
                        decryptedChar = ( char1 ^ currChar );
                        currKey=2;
                    }
                    else if (currKey == 2)
                    {
                        decryptedChar = ( char2 ^ currChar );
                        currKey=3;
                    }
                    else if (currKey == 3)
                    {
                        decryptedChar = ( char3 ^ currChar );
                        currKey=1;
                    }
                    slidingWindow.push_back(decryptedChar);
                    if(slidingWindow.size() > 3)
                    {
                        slidingWindow.pop_front();
                    }
                    if(slidingWindow[0] == 't' && slidingWindow[1] == 'h' && slidingWindow[2] =='e'){
                        
                        theTest=true;
                    }
                    if(slidingWindow[0] == 'a' && slidingWindow[1] == 'n' && slidingWindow[2] =='d'){
                        
                        andTest=true;
                    }
                    if(slidingWindow[0] == 'n' && slidingWindow[1] == 'o' && slidingWindow[2] =='t'){
                        
                        notTest=true;
                    }
                    decryptedMessage.push_back(decryptedChar);
                }
                if(theTest && andTest && notTest)
                {

                    cout <<"key is: " << char1 << char2<< char3 << endl;
                    int sum = 0;
                    for(int kk =0; kk<decryptedMessage.size(); kk++)
                    {
                        cout<<decryptedMessage[kk];
                        sum+=decryptedMessage[kk];
                    }
                    cout<<endl;
                    cout << sum << endl;
                }
                 
            }

        }

    }




}
