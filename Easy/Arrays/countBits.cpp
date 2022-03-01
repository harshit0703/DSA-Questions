#include <bits/stdc++.h>
using namespace std;

int countBits(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int temp = n % 2;
        n = n / 2;
        if (temp == 1)
            ans++;
    }

    return ans;
}

int main()
{
    for (int i = 0; i <= 5; i++)
    {
        cout << countBits(i) << endl;
    }

    cout << __builtin_popcount(5); // this builtin function directly returns the number of 1's present in the binary representation of that number
    return 0;
}