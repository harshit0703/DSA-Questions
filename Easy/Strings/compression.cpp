#include <iostream>
#include <string>
using namespace std;

int main()
{
    // remove the consecutive repeating chars
    string str;
    cin>>str;
    for(int i=1; i<str.size(); i++){
        if (str[i] != str[i-1]){
            cout<<str[i-1];
        } 
    }
    return 0;
}