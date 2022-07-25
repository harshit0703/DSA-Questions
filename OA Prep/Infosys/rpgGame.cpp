#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{

    if (a.first < b.first)
        return true;
    if (a.first > b.first)
        return false;

    // if the power is same then put the one with more bonus forward

    if (a.second >= b.second)
        return true;

    return false;
}

int main()
{
    int n;
    cin >> n;
    int initExp;
    cin >> initExp;

    vector<int> power, bonus;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        power.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        bonus.push_back(temp);
    }

    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++)
    {

        data.push_back({power[i], bonus[i]});
    }

    sort(data.begin(), data.end(), cmp);

    for (auto i : data)
    {
        cout << i.first << "-" << i.second;
        cout << endl;
    }

    int cnt = 0;
    int i = 0;

    while (i < n && initExp >= data[i].first)
    {

        cnt++;
        initExp += data[i++].second;
    }

    cout << "The number of monsters that can be defeated are -> " << cnt;

    return 0;
}