#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &money, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int robCurr = rob(money, n - 2, dp) + money[n];
    int robNext = rob(money, n - 1, dp);

    return dp[n] = max(robCurr, robNext);
}

int main()
{
    vector<int> money = {1, 2, 3, 4};
    vector<int> dp(101, -1);

    cout << rob(money, money.size() - 1, dp);
    return 0;
}