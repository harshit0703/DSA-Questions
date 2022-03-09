#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> nums, int target)
{
    // the main idea is to have two pointers and the remaining target will be found using the two-sum approach

    vector<vector<int>> res;

    if (nums.size() == 0)
        return {};

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target_2 = target - nums[i] - nums[j];

            // apply two sum approach to find the target_2
            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {

                if (nums[front] + nums[back] < target_2)
                {
                    front++;
                }

                else if (nums[front] + nums[back] > target_2)
                {
                    back--;
                }

                else
                {
                    // found the target_2
                    vector<int> temp(4, 0);
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[front];
                    int d = nums[back];

                    temp = {a, b, c, d};
                    res.push_back(temp);

                    // removing duplicates for third element
                    while (front < back && c == nums[front])
                        front++;

                    // removing duplicates for fourth element
                    while (front < back && d == nums[back])
                        back--;
                }
            }
            // removing duplicates for second element
            while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
        }

        // removing duplicates for the first element
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }

    // main catch of this question is to process the duplicates
    // TC = O(N^3) N^2 for nested loops and NlogN for sorting
    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = solve(nums, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}