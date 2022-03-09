#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n, vector<int> dp)
{
    if (n >= nums.size())
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int rob = solve(nums, n + 2, dp) + nums[n];

    int dontRob = solve(nums, n + 1, dp);

    return dp[n] = max(rob, dontRob);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    // since the houses are present in circle we cannot include both the first and the last house
    // but the remaining logic will be the same as houseRobber
    // so simply divide the given array into two parts and find the max of them

    vector<int> first, last;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i != nums.size() - 1)
            first.push_back(nums[i]);
        if (i != 0)
            last.push_back(nums[i]);
    }

    vector<int> dp(1001, -1);

    int a = solve(first, 0, dp);

    for (auto i : dp)
        i = -1;

    int b = solve(last, 0, dp);

    cout << max(a, b);

    return 0;
}