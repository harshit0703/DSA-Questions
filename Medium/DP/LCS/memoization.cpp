#include<bits/stdc++.h>
using namespace std;

int DP[1000][1000];

int LCS(string str1, string str2, int n, int m){

    if(n == 0 || m == 0){
        return 0;
    }
    
    if(DP[n-1][m-1] != -1){
        return DP[n-1][m-1];        // overlapping cases handling
    }

    if(str1[n-1] == str2[m-1]){
        return DP[n-1][m-1] = LCS(str1, str2, n-1, m-1) + 1;   // if the last ch is equal it can be a possible subsequence
    }

    else{

        return DP[n-1][m-1] = max(LCS(str1, str2, n-1, m), LCS(str1, str2, n, m-1));

    }

}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";
    memset(DP, -1, sizeof(DP));
    int ans = LCS(str1, str2, str1.length(), str2.length());
    cout<<ans;
    return 0;
}