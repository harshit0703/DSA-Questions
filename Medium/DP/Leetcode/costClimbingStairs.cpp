#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int solve(vector<int> &cost, int n)
{
    if (n == 0 || n == 1)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int jump1 = solve(cost, n - 1) + cost[n - 1];
    int jump2 = solve(cost, n - 2) + cost[n - 2];

    return dp[n] = min(jump1, jump2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    memset(dp, -1, sizeof(dp));
    return solve(cost, cost.size());
}

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost);
    return 0;
}