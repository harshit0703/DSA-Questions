#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int st, int mid, int en)
{

    int n1 = mid - st + 1;
    int n2 = en - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[st + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = st;
    int inversions = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
            inversions += mid - i + 1;
        }
    }

    while (i < n1)
    {
        arr[k++] = a[i++];
    }

    while (j < n2)
    {
        arr[k++] = b[j++];
    }

    return inversions;
}

int mergeSort(int arr[], int st, int en)
{
    int inversions = 0;
    if (st < en)
    {
        int mid = st + (en - st) / 2;
        inversions += mergeSort(arr, st, mid);
        inversions += mergeSort(arr, mid + 1, en);
        inversions += merge(arr, st, mid, en);
    }

    return inversions;
}

int countInversions(int arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    int arr[] = {2, 5, 1, 3, 4};
    cout << countInversions(arr, 5);
    return 0;
}