#include<bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int n, int m){

    if(n == 0 || m == 0){
        return 0;
    }
    
    if(str1[n-1] == str2[m-1]){
        return LCS(str1, str2, n-1, m-1) + 1;   // if the last ch is equal it can be a possible subsequence
    }

    else{

        return max(LCS(str1, str2, n-1, m), LCS(str1, str2, n, m-1));   // here we have 2 choice either to shrink string 1 or 2

    }

}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";
    int ans = LCS(str1, str2, str1.length(), str2.length());
    cout<<ans;
    return 0;
}