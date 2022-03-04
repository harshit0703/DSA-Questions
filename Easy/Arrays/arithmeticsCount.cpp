#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int cnt = 0;
    while (n > 2)
    {
        cnt += n - 2;
        n--;
    }
    return cnt;
}

int main()
{
    // given an array find the number of possible arithmetic subarrays in this
    // number of sub-arrays of size size k = n - k + 1

    vector<int> v = {1, 3, 5, 7};

    // make a sliding window to find the a subarray that is an AP

    int i = 0, j = 2;
    int cd = v[1] - v[0];
    int cnt = 0;
    while (j < v.size())
    {

        if (v[j] - v[j - 1] != cd)
        {
            cd = v[j] - v[j - 1];
            cnt += solve(j - i + 1);
            i = j;
        }

        j++;
    }

    if (cnt == 0 && i == 0)
    {
        cnt = solve(v.size());
    }

    cout << cnt;

    return 0;
}