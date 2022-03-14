#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int en)
{

    vector<int> temp;
    int i = st;
    int j = mid + 1;
    int inversions = 0;

    while (i <= mid && j <= en)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }

        else
        {
            // since if arr[i] > arr[j] and we know it is a sorted arr till mid we can say that for all elements in this arr they will make an inversion with arr[j]

            inversions += mid - i + 1;
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= en)
        temp.push_back(arr[j++]);

    for (int i = st; i <= en; i++)
    {
        arr[i] = temp[i - st];
    }

    return inversions;
}

int mergeSort(vector<int> &arr, int st, int en)
{
    int inversions = 0;
    if (st < en)
    {
        int middle = st + (en - st) / 2;

        inversions += mergeSort(arr, st, middle);
        inversions += mergeSort(arr, middle + 1, en);
        inversions += merge(arr, st, middle, en);
    }

    return inversions;
}

int main()
{
    // inversion is basically a pair of couple of elements inside the array such that
    // arr[i] > arr[j] && i < j
    // brute force will be simply using two nested loops and finding the pairs
    // more optimized approach includes use of merge sort

    vector<int> arr = {5, 3, 2, 1, 4};
    cout << mergeSort(arr, 0, arr.size() - 1);

    return 0;
}