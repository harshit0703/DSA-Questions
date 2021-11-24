#include<bits/stdc++.h>
using namespace std;

// equal sum partition is nothing but a simple extension to subsetSum 


bool subsetSum(int arr[], int n, int sum){
    if(n == 0){
        return true;
    }

    if(arr[n-1] > sum){
        subsetSum(arr, n-1, sum);
    }

    bool included = subsetSum(arr, n-1, sum - arr[n-1]);
    bool not_included = subsetSum(arr, n-1, sum);

    return included || not_included;

}


bool equalSumPartition(int arr[], int n){
    // since we have to make 2 equal partitions the sum of the elements of the array need to be an even number otherwise
    // it is not possible 

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if(sum % 2 != 0){
        return false;
    }

    // now there is a possibility of having a partition 
    // if you think carefully if we will check for sum/2 subset and if it is possible then the other half is also a subset and the
    // partitions are possible

    if(subsetSum(arr, n, sum/2)){
        return true;        // in this way we reduced our problem to subset sum
    }
    
    return false;
}


int main()
{
    int arr[] = {5, 1, 11, 5};
    cout<<equalSumPartition(arr, 4);
    return 0;
}