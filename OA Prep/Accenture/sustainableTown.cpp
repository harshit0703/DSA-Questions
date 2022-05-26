#include <bits/stdc++.h>
using namespace std;

bool strictlyInc(vector<int> &nums)
{
    for (int i = 1; i <= nums.size(); i++)
    {
        if (nums[i] <= nums[i - 1])
            return false;
    }

    return true;
}

bool solve(int idx, vector<int> nums, int days)
{

    if (days == 0)
    {
        if (strictlyInc(nums))
            return true;
        return false;
    }

    if (idx >= nums.size() - 2)
        return false;

    bool pick = false;
    bool notPick = false;

    if (nums[idx + 1] > nums[idx] && nums[idx + 2] > nums[idx])
    {
        notPick = solve(idx + 1, nums, days);
    }

    else
    {
        nums[idx] += nums[idx + 1];
        nums[idx] += nums[idx + 2];
        nums.erase(nums.begin() + idx + 1);
        nums.erase(nums.begin() + idx + 2);
        pick = solve(idx + 1, nums, days - 1);
    }

    return pick || notPick;
}

bool sustainableTown(vector<int> &nums, int days)
{

    return solve(0, nums, days);
}

int main()
{
    vector<int> nums = {2, 6, 1, 2};
    cout << sustainableTown(nums, 1);
    return 0;
}