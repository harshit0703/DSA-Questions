#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v)
{

    // base conditions
    if (v.size() == 0)
        return 0;
    if (v.size() == 1)
        return v[0];

    // we can chose any element in the whole vector to start with

    int ans = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        int j = 0;
        vector<int> temp;
        // suppose we chose  the ith element we need to make another vector not including ith element and its predecessor and successors
        while (j < v.size() && j != i)
        {
            if (abs(v[i] - v[j] != 1))
            {
                temp.push_back(v[j]);
            }
            j++;
        }

        // for (auto i : temp)
        //     cout << i << endl;

        int sum = solve(temp) + v[i];
        ans = max(ans, sum);
    }

    return ans;
}

int deleteEarn(vector<int> &v)
{
    if (v.size() == 1)
        return v[0];

    int ans = solve(v);
    return ans;
}

int main()
{
    vector<int> v = {2, 3, 4};
    cout << deleteEarn(v);
    return 0;
}