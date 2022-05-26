#include <bits/stdc++.h>
using namespace std;

bool allSame(vector<int> v)
{
    int temp = v[0];
    for (auto i : v)
    {
        if (i != temp)
            return false;
    }

    return true;
}

int solve(vector<int> &tops, vector<int> &bottoms, int n, int rotations)
{
    if (n < 0)
    {
        return INT_MAX;
    }

    if (allSame(tops) || allSame(bottoms))
    {
        return rotations;
    }

    int notRotate = solve(tops, bottoms, n - 1, rotations);

    int temp = tops[n - 1];
    tops[n - 1] = bottoms[n - 1];
    bottoms[n - 1] = temp;

    int rotate = solve(tops, bottoms, n - 1, rotations + 1);

    return min(notRotate, rotate);
}

int main()
{
    vector<int> tops = {3, 5, 1, 2, 3};
    vector<int> bottoms = {3, 6, 3, 3, 4};

    int ans = solve(tops, bottoms, tops.size(), 0);

    if (ans == INT_MAX)
        ans = -1;

    cout << ans;

    return 0;
}