#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int frogJump(vector<int> &nums, int k, int n)
{

    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int res = frogJump(nums, k, n - i) + abs(nums[n] - nums[n - i]);
            ans = min(res, ans);
        }
    }

    return dp[n] = ans;
}

int main()
{
    vector<int> nums = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    memset(dp, -1, sizeof(dp));
    cout << frogJump(nums, 4, nums.size() - 1);
    return 0;
}