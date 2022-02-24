#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int st = 0;
    int en = str.length() - 1;
    while(st < en){
        if(str[st] != str[en]) return false;
        st++;
        en--;
    }

    return true;
}

int solve(string str, int len){

    int size = str.length();

    if (len > size) return 0;

    int i = 0;
    int j = 0;
    int ans = 0;

    string temp = "";

    while (j < size)
    {
        temp += str[j];
        if(j - i + 1 == len){
            if(isPalindrome(temp)) ans++;
            temp = temp.substr(1);
            i++;
        }
        j++;
    }

    return ans;

}

int main()
{
    int strlen; cin>>strlen;
    string str;
    for(int i = 0; i < strlen; i++){
        char ch; cin>>ch;
        str += ch;
    }
    int cnt; cin>>cnt;
    vector<int> len;
    for(int i = 0; i < cnt; i++){
        int temp; cin>>temp;
        len.push_back(temp);
    }
    int ans = 0;
    for(int i = 0; i < cnt; i++){
        ans += solve(str, len[i]);
    }
    cout<<ans;
    return 0;
}