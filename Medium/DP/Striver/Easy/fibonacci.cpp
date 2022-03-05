#include <bits/stdc++.h>
using namespace std;

vector<int> dp(101, -1); // memoization

int solve(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n]; // by doing so we will be eliminating overlapping sub-problems

    return dp[n] = solve(n - 1) + solve(n - 2);
}

int main()
{
    int a = 0;
    int b = 1;
    int i = 0;
    int c;
    while (i < 8)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    cout << endl;
    cout << solve(4);
    return 0;
}