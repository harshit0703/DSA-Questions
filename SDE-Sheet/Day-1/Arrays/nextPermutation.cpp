#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &v)
{

    // step - 1 find an element from the reverse which is not in the ascending order
    int i;
    int temp = 0;
    for (i = v.size() - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            break;
        }
    }

    if (i == -1)
    {
        // all the elements were present in the ascending order which means it was the last permutation
        reverse(v.begin(), v.end());
        return;
    }

    // step - 02 find the first element greater than this and swap it with the temp
    for (int j = v.size() - 1; j >= 0; j--)
    {
        if (v[j] > v[i])
        {
            swap(v[i], v[j]);
            break;
        }
    }

    // step - 03 finally reverse the array after swapping  the elements
    reverse(v.begin() + i + 1, v.end());

    // overall TC = O(3*n) = O(n)
}
int main()
{
    vector<int> v = {2, 3, 6, 5, 4, 1};
    nextPermutation(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}