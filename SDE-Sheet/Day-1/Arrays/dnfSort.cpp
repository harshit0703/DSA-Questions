#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we are only given with 3 differt nos i.e 0, 1, 2

    vector<int> v = {0, 0, 1, 2, 1, 2, 1, 0};

    // this method uses a three pointer approach so that we can process the sorting algorithm in O(n) time and it is only possible for three diff elements

    int st = 0;
    int mid = 0;
    int en = v.size() - 1;

    while (mid < en)
    {
        if (v[mid] == 1)
        {
            mid++;
        }
        else if (v[mid] == 0)
        {
            swap(v[mid], v[st]);
            mid++;
            st++;
        }
        else
        {
            swap(v[mid], v[en]);
            en--;
        }
    }

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}