#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we will be formulating two equations in this question
    // x = missing element   y = repeating element
    // s = sum of n natural nos   s1 = sum of array elements
    // s - s1 = x - y = s'
    // p = prod of n natural nos  p1 = prod of array elements
    // p - p1 = (x - y) (x + y) = p'
    // solving these eqns = (s' + p'/s') / 2 = x

    vector<int> v = {3, 1, 2, 5, 3};
    int n = v.size();

    long long arraySum = 0, arrayProdSum = 0;

    long long actualSum = ((n) * (n + 1)) / 2;
    long long actualProdSum = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < v.size(); i++)
    {
        arraySum += v[i];
        arrayProdSum += pow(v[i], 2);
    }

    int missing = ((actualSum - arraySum) + (actualProdSum - arrayProdSum) / (actualSum - arraySum)) / 2;

    int repeating = missing - actualSum + arraySum;

    cout << missing << " " << repeating;

    return 0;
}