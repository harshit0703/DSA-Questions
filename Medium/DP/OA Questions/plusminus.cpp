#include <bits/stdc++.h>
using namespace std;
#define l 1000000007
long long int res = 0;
int solve(string str, unordered_set<int> &s, int num, int idx, int n, vector<vector<int>> &dp)
{
    if (idx == n)
    {

        return 1;
    }

    if (dp[idx][num] != -1)
        return dp[idx][num];

    long long int res = 0;

    for (int i = 1; i <= n + 1; i++)
    {
        if (s.find(i) == s.end())
        {
            if ((str[i] == '-' && num > i) || (str[i] == '+' && num < i))
            {
                s.insert(num);
                res += (solve(str, s, i, idx + 1, n, dp)) % l;
                s.erase(num);
            }
        }
    }

    return dp[idx][num] = res;
}
int main()
{
    string str;
    int n = str.size();
    unordered_set<int> s;
    long long int res = 0;
    vector<vector<int>> dp(n, vector<int>(n + 2, -1));
    for (int num = 1; num <= n + 1; num++)
    {
        s.insert(num);
        res += (solve(str, s, num, 0, n, dp)) % l;
        s.erase(num);
    }
    cout << res;
    return 0;
}
