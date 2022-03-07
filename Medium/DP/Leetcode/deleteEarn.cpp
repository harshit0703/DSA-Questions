#include <bits/stdc++.h>
using namespace std;

int deleteEarn(vector<int> &nums, int idx, vector<int> &dp)
{

    if (idx >= nums.size())
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int pts = nums[idx];
    int curr = nums[idx];
    int temp = idx + 1;

    while (temp < nums.size() && curr == nums[temp])
    {
        pts += nums[idx];
        temp++;
    }

    while (temp < nums.size() && nums[temp] - curr == 1)
    {
        temp++;
    }

    int earn = deleteEarn(nums, temp, dp) + pts;
    int dontEarn = deleteEarn(nums, idx + 1, dp);

    return dp[idx] = max(earn, dontEarn);
}

int main()
{
    vector<int> nums = {2, 3, 3, 3, 2, 4};
    vector<int> dp(20001, -1);
    cout << deleteEarn(nums, 0, dp);
    return 0;
}