#include <bits/stdc++.h>
using namespace std;

int jumps(vector<int> &nums, int index, vector<int> &dp)
{

    if (index >= nums.size() - 1)
        return 0;

    if (dp[index] != 10001)
        return dp[index];

    int maxJump = nums[index];

    for (int i = 1; i <= maxJump; i++)
    {

        dp[index] = min(dp[index], jumps(nums, index + i, dp) + 1);
    }

    return dp[index];
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> dp(nums.size(), 10001);
    cout << jumps(nums, 0, dp);
    return 0;
}