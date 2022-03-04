#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int> &b, int m, int n)
{
    // considering the length of vector a is greater
    int i = 0;

    while (i < m)
    {

        int j = 0;
        while (b[j] > a[i])
            j++;

        if (j != n)
        {
            // we have found an element that is smaller than  the current element
            int temp = a[i];
            a[i] = b[j++];
            while (j < n && b[j] < temp)
            {
                b[j - 1] = b[j];
                j++;
            }
            b[--j] = temp;
        }

        i++;
    }

    int temp = m;
    int cnt = 0;

    while (temp < a.size())
    {
        a[temp++] = b[cnt++];
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    merge(a, b, 3, 3); // simply merge the two arrays without even using any extra space
    for (auto i : a)
        cout << i << " ";
    // for (auto i : b)
    //     cout << i << " ";
    return 0;
}