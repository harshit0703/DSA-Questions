#include <iostream>
#include <string>
using namespace std;

int main()
{
    // find the char with the max frequency in the string
    // we can only have a single word as a string here as we cannot do the same with a sentence
    string str;
    cin>>str;
    
    int arr[26];
    for(int i=0; i<26; i++){
        arr[i] = 0;
    }

    for(int i=0; i<str.size(); i++){
        arr[str[i] - 'a']++;
    }

    int max_freq = 0;
    char ans;
    for(int i=0; i<26; i++){
        if(max_freq < arr[i]){
            max_freq = arr[i];
            ans = i + 'a';
        }
    }

    cout<<max_freq<<" "<<ans;
}