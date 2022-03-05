#include <bits/stdc++.h>
using namespace std;

int solve(int stairs)
{
    if (stairs < 0)
        return 0;
    if (stairs == 0 || stairs == 1)
        return 1;

    // if there are more than 1 stair we have a choice to make a jump of either 1 stair or couple of stairs

    return solve(stairs - 1) + solve(stairs - 2);
}

int main()
{
    cout << solve(3);
    return 0;
}