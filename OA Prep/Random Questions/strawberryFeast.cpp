#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, int cap, vector<int> &dp)
{

    if (i > n)
        return 0;

    if (i == n)
        return 1;

    if (dp[i] != -1)
        return dp[i];

    int ans = 0;

    for (int k = 1; k <= cap; k++)
    {

        ans += solve(i + k, n, cap, dp);
    }

    return dp[i] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int cap;
    cin >> cap;

    int ans = solve(0, n, cap, dp);
    cout << ans;
    return 0;
}