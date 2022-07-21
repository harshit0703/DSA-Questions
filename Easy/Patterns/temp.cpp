#include <bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
representation of positive integer n */
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
        cout << (n >> 1) << " ";
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/* Program to test function countSetBits */
int main()
{
    int i = 2;
    cout << endl
         << countSetBits(i);
    return 0;
}