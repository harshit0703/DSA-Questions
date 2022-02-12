#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

void printSubSeq(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }

    char ch = str[0];
    str = str.substr(1);
    printSubSeq(str, ans + ch);
    printSubSeq(str, ans);
}

int LCS(string a, int n, string b, int m){
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(a[n-1] == b[m-1]){
        return dp[n][m] = LCS(a, n - 1, b, m - 1) + 1;
    }

    else{
        int travela = LCS(a, n-1, b, m);
        int travelb = LCS(a, n, b, m-1);
        return dp[n][m] = max(travela, travelb);
    }
}

int LCSTopDown(string a, int n, string b, int m){

    int solve[n+1][m+1];

    // initialization
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < m + 1; j++){
            if(i == 0 || j == 0) solve[i][j] = 0;
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(a[i-1] == b[j-1]){
                solve[i][j] = solve[i-1][j-1] + 1;
            }
            else{
                int travela = solve[i-1][j];
                int travelb = solve[i][j-1];
                solve[i][j] = max(travela, travelb);
            }
        }
    }

    return solve[n][m];

}


string PrintLCS(string a, int n, string b, int m){
    if(n == 0 || m == 0) return "";


    if(a[n-1] == b[m-1]){
        return PrintLCS(a, n - 1, b, m - 1) + a[n-1];
    }

    else{
        string travela = PrintLCS(a, n-1, b, m);
        string travelb = PrintLCS(a, n, b, m-1);
        if(travela.length() > travelb.length()){
            return travela;
        }else{
            return travelb;
        }
    }
}

string PrintLCSTopDown(string a, int n, string b, int m){

    string solve[n+1][m+1];

    // initialization
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < m + 1; j++){
            if(i == 0 || j == 0) solve[i][j] = "";
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(a[i-1] == b[j-1]){
                solve[i][j] = solve[i-1][j-1] + a[i-1];
            }
            else{
                string travela = solve[i-1][j];
                string travelb = solve[i][j-1];
                if(travela.length() > travelb.length()){
                    solve[i][j] = travela;
                }else{
                    solve[i][j] = travelb;
                }
            }
        }
    }

    return solve[n][m];

}

int SCS(string a, int n, string b, int m){
    if(n == 0) return m;
    if(m == 0) return n;
    if(a[n-1] == b[m-1]) return SCS(a, n-1, b, m-1) + 1;
    else{
        return min(SCS(a, n-1, b, m) + 1, SCS(a, n, b, m-1) + 1);
    }
}

string PrintSCS(string a, int n, string b, int m){
    if(n == 0) return b.substr(0, m);
    if(m == 0) return a.substr(0, n);
    if(a[n-1] == b[m-1]) return PrintSCS(a, n-1, b, m-1) + a[n-1];
    else{
        string first = PrintSCS(a, n-1, b, m) + a[n-1];
        string second = PrintSCS(a, n, b, m-1) + b[m-1];
        if(first.length() < second.length()){
            return first;
        }else{
            return second;
        }
    }
}

bool isPalindrome(string str){
    int i = 0;
    int j = str.length() - 1;
    while(i < j){
        if(str[i] != str[j])return false;
        i++;
        j--;
    }

    return true;
}

void palindromicSubSeq(string str, string ans, string &lps){
    if(str.length() == 0){
        if(isPalindrome(ans)){
            // int len = ans.length();
            // lps = max(len, lps);
            if(lps.length() < ans.length()) lps = ans;
        }
        return;
    }

    char ch = str[0];
    str = str.substr(1);
    palindromicSubSeq(str, ans + ch, lps);
    palindromicSubSeq(str, ans, lps);

}

int main()
{
    // subsequence is a part of the string which may not be continuous but the order of the elements will remain the same
    // printSubSeq("abc", "");
    memset(dp, -1, sizeof(dp));
    cout<<LCS("aggtab", 6, "gxtxayb", 7)<<endl;
    cout<<LCSTopDown("aggtab", 6, "gxtxayb", 7)<<endl;
    cout<<PrintLCS("aggtab", 6, "gxtxayb", 7)<<endl;
    cout<<PrintLCSTopDown("aggtab", 6, "gxtxayb", 7) << endl;
    cout<<PrintSCS("aggtab", 6, "gxtxayb", 7) << endl;
    cout<<PrintSCS("geek", 4, "eke", 3) << endl;
    cout<<SCS("geek", 4, "eke", 3) << endl;
    string n = "";
    palindromicSubSeq("agbcba", "", n); cout<<n;
    return 0;
}