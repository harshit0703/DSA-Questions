#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int st = 0;
    int en = str.length() - 1;
    while(st <= en){
        if(str[st] != str[en]){
            return false;
        }
        st++;
        en--;
    }
    return true;
}

void biggestNumber(string str){
    sort(str.begin(), str.end(), greater<int>());
    // by doing so the characters inside the string will get sorted in descending order
    cout<<str;

}

void caseConversion(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] <= 'z' && str[i] >= 'a'){
            str[i] = toupper(str[i]);
        }
        else if(str[i] <= 'Z' && str[i] >= 'A'){
            str[i] = tolower(str[i]);
        }
    }
    cout<<str;
}

void maxFreq(string str){
    unordered_map<char, int>mp;
    for(int i = 0; i < str.length(); i++){
        mp[str[i]]++;
    }
    int maxChar = INT_MIN;
    char ans;
    for(auto i : mp){
        // cout<<i.first<<" "<<i.second<<endl;
        if(i.second > maxChar){
            maxChar = i.second;
            ans = i.first;
        }
    }
    cout<<ans<<"->"<<maxChar;
}

int main()
{
    string str = "harshitguptaismyname";
    // cout<<isPalindrome(str)<<endl;
    // biggestNumber(str);
    // caseConversion(str);
    maxFreq(str);
    return 0;
}