#include <bits/stdc++.h>
using namespace std;

int solve(int st, int en, int i, int total, vector<vector<int>> &nums)
{

    if (i == nums.size())
    {

        if (en != total)
            return 1e9;
        return 0;
    }

    int include = 1e9;
    int notInclude = solve(st, en, i + 1, total, nums);

    if (nums[i][0] <= en + 1)
        include = solve(nums[i][0], max(en, nums[i][1]), i + 1, total, nums) + 1;

    return min(include, notInclude);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++)
    {
        int st, en;
        cin >> st >> en;
        nums[i].push_back(st);
        nums[i].push_back(en);
    }

    int total;
    cin >> total;

    sort(nums.begin(), nums.end());

    int ans = solve(0, 0, 0, total, nums);

    if (ans == 1e9)
        return -1;

    cout << ans;

    return 0;
}