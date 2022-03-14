#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m)
{

    for (int i = 0; i < n; i++)
    {

        if (arr1[i] > arr2[0])
        {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
        }

        int first = arr2[0];

        // put this in the correct position in the second array

        int j = 1;
        while (j < m && arr2[j] < first)
        {
            arr2[j - 1] = arr2[j];
            j++;
        }

        arr2[j - 1] = first;
    }
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    merge(arr1, 5, arr2, 3);
    for (auto i : arr1)
        cout << i << " ";
    for (auto i : arr2)
        cout << i << " ";
    return 0;
}