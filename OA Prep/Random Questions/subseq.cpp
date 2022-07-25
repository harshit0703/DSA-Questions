#include <bits/stdc++.h>
using namespace std;
int dp[100000][2];

int cnt(string str, string patt, int i, int j)
{
    if (j == 2)
        return 1;

    if (i >= str.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int op1 = 0, op2 = 0;

    if (str[i] == patt[j])
        op1 = cnt(str, patt, i + 1, j + 1) + cnt(str, patt, i + 1, j);

    else if (str[i] != patt[j])
        op2 = cnt(str, patt, i + 1, j);

    return dp[i][j] = max(op1, op2);
}

int main()
{
    string str;
    string patt;
    cin >> str;
    cin >> patt;

    memset(dp, -1, sizeof(dp));

    int first = cnt(str + patt[1], patt, 0, 0);

    memset(dp, -1, sizeof(dp));

    int second = cnt(patt[0] + str, patt, 0, 0);

    cout << max(first, second);

    return 0;
}