#include<bits/stdc++.h>
using namespace std;

int LPS(string str1, string str2, int n, int m){

    int DP[n+1][m+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++){
            if(i==0 || j==0){
                DP[i][j] = 0;           // initialization
            }
        }
    }
    
     for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++){
            
            if(str1[i-1] == str2[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }

            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }

        }
    }

    return DP[n][m];

}

int main()
{
    string str1 = "abcgbha";
    // the main catch of this question is we are only provided with one string and we need to generate the second by ourselves
    string str2 = str1;
    reverse(str2.begin(), str2.end()); 
    int lpsLength = LPS(str1, str2, str1.length(), str2.length());    // so the LPS is the LCS between the given string and its reverse
    int deletion = str1.length() - lpsLength;
    cout<<deletion;
    return 0;
}