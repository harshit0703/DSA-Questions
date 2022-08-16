#include <bits/stdc++.h>
using namespace std;

int number_of_intelligent_group(int length, int *intelligence, int k)
{

    // we will be using the concept of sliding window in this question
    // it will be a variable size sliding window with sum of elements equal to k
    int i = 0, j = 0;
    int sum = 0, cnt = 0;
    // initially the number of ways are 0 and the current sum is also 0

    while (j < length)
    {

        sum += intelligence[j]; // now as we go we add the student iq

        if (sum == k) // if it is equal to k then this becomes a possible way and we update the ways
            cnt++;

        if (sum > k) // once the sum is greater than k we need to shrink the window till it becomes less than or equal to k again
        {
            while (sum > k)
            {
                sum -= intelligence[i];
                i++;
            }
            if (sum == k) // if it becomes equal to k again we need to count this as well before moving ahead
                cnt++;
        }
        j++;
    }

    return cnt; // at the end return all possible ways
}

int main()
{
    int arr[] = {1, 2, 3};
    cout << number_of_intelligent_group(3, arr, 3);
    return 0;
}