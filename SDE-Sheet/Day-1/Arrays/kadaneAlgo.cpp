#include <bits/stdc++.h>
using namespace std;

int main()
{
    // kadane's algorithm is used to find the max sum subarray it simply says that if the sum gets lesser than 0 then reset the sum to zero

    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum < 0)
        {
            sum = 0;
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}