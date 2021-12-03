#include<bits/stdc++.h>
using namespace std;

string printLCS(string str1, string str2, int n, int m){

    string DP[n+1][m+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++){
            
            if(i == 0 || j == 0){
                DP[i][j] = "";
            }

        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++){
            
            if(str1[i-1] == str2[j-1]){
                DP[i][j] = DP[i-1][j-1] + str1[i-1];
            }

            else{

                if(DP[i-1][j].length() >= DP[i][j-1].length()){
                    DP[i][j] = DP[i-1][j];
                }

                else{
                    DP[i][j] = DP[i][j-1];
                }

            }

        }
    }

    return DP[n][m];

}

int main()
{
    string str1 = "acbcf";
    string str2 = "abcdgf";
    string ans = printLCS(str1, str2, str1.length(), str2.length());
    cout<<ans;
    return 0;
}