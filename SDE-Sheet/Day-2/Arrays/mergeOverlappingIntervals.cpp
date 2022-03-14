#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // first sort the given vector
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++)
    {
        int st = intervals[i][0];
        int en = intervals[i][1];

        int j = i + 1;
        while (j < intervals.size() && intervals[j][0] <= en)
        {
            en = max(en, intervals[j][1]);
            j++;
        }

        if (j != i + 1)
            i = j - 1;

        ans.push_back({st, en});
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {3, 6}, {8, 10}, {13, 15}};
    vector<vector<int>> ans = mergeIntervals(intervals);
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