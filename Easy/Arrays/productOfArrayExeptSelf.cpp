#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> left(nums.size());
    vector<int> right(nums.size());

    left[0] = 1;
    right[right.size() - 1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int temp = left[i] * right[i];
        ans.push_back(temp);
    }

    return ans;

    // since we are using couple of extra vectors we are using an O(N) extra space and a linear time complexity
}

int main()
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> ans = productExceptSelf(nums);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}