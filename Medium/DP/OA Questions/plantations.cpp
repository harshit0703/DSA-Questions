#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int solve(int prev, int idx, int n, vector<vector<int>> &dp)
{

    if (idx == n)
    {
        return 1;
    }

    if (dp[idx][prev] != -1)
        return dp[idx][prev];

    int ans = 0;

    if (prev == 1)
    {
        ans = solve(0, idx + 1, n, dp);
        ans %= mod;
    }

    else
    {
        ans = solve(1, idx + 1, n, dp);
        ans %= mod;
        ans += solve(0, idx + 1, n, dp);
        ans %= mod;
    }

    return dp[idx][prev] = ans;
}

int calculatePlantations(int n)
{

    if (n == 1)
        return 2;

    vector<vector<int>> dp(n, vector<int>(2, -1));

    int ans = solve(0, 1, n, dp);
    ans %= mod;
    ans += solve(1, 1, n, dp);
    ans %= mod;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << calculatePlantations(n);
    return 0;
}