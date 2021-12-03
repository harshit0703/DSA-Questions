#include<bits/stdc++.h>
using namespace std;

string printLCS(string str1, string str2, int n, int m){

    if(n==0 || m==0){
        return "";
    }

    if(str1[n-1] == str2[m-1]){
        return printLCS(str1, str2, n-1, m-1) + str1[n-1];
    }

    string first = printLCS(str1, str2, n-1, m);
    string second = printLCS(str1, str2, n, m-1);

    if(first.length() >= second.length()){
        return first;
    }

    return second;

}

int main()
{
    string str1 = "acbcf";
    string str2 = "abcdgf";
    string ans = printLCS(str1, str2, str1.length(), str2.length());
    cout<<ans;
    return 0;
}