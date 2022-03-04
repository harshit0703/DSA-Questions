#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int st, int mid, int en)
{

    int pairCnt = 0;
    int i = st;
    int j = mid + 1;
    for (; i <= mid; i++)
    {
        while (j <= en && nums[i] > 2 * nums[j])
        {
            j++;
        }
        pairCnt += j - (mid + 1);
    }

    vector<int> temp;

    i = st, j = mid + 1;

    while (i <= mid && j <= en)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i++]);
    }

    while (j <= en)
    {
        temp.push_back(nums[j++]);
    }

    for (int i = st; i <= en; i++)
    {
        nums[i] = temp[i - st];
    }
    return pairCnt;
}

int mergeSort(vector<int> &nums, int st, int en)
{

    int cnt = 0;

    if (st < en)
    {
        int mid = st + (en - st) / 2;
        cnt += mergeSort(nums, st, mid);
        cnt += mergeSort(nums, mid + 1, en);
        cnt += merge(nums, st, mid, en);
    }

    return cnt;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> v = {40, 25, 19, 12, 9, 6, 2};
    int ans = reversePairs(v);
    cout << ans;
    return 0;
}