#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums, int index, vector<int> &dp)
{

    // if we have jumped beyond the size of the array
    if (index >= nums.size())
        return false;

    // if we have reached the last index it is a possible path
    if (index == nums.size() - 1)
        return true;

    if (dp[index] != -1)
        return dp[index];

    int maxJump = nums[index];

    for (int i = 1; i <= maxJump; i++)
    {
        if (canJump(nums, index + i, dp))
        {
            return dp[index] = true;
        }
    }

    return dp[index] = false;
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    vector<int> dp(10001, -1);
    cout << canJump(nums, 0, dp);
    return 0;
}