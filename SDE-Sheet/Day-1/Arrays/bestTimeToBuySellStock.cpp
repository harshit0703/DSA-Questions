#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we just need to find the max on the right
    vector<int> v = {7, 6, 4, 3, 1};
    int ltr[v.size()];
    ltr[v.size() - 1] = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--)
    {
        ltr[i] = max(v[i], ltr[i + 1]);
    }

    int profit = 0;

    for (int i = 0; i < v.size(); i++)
    {
        profit = max(profit, ltr[i] - v[i]);
    }

    cout << profit;

    return 0;
}