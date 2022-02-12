#include<bits/stdc++.h>
using namespace std;

int dp[102][100002];

bool subsetSumTopDown(int arr[], int sum, int n){
    int solve[n+1][sum+1];
    
    //initialization

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            // dealing with only first row and first column
            if(i == 0 || j == 0){
                if(i == 0) solve[i][j] = 0;
                if(j == 0) solve[i][j] = 1;
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){

            if(arr[i-1] > j){
                solve[i][j] = solve[i-1][j];
            }

            else{

                solve[i][j] = (solve[i-1][j-arr[i-1]] || solve[i-1][j]);

            }

        }
    }

    return solve[n][sum];
}

bool subsetSum(int arr[], int sum, int n){
    if(sum == 0) return true;
    if(n == 0) return false;

    if(dp[n][sum] != -1)return dp[n][sum];

    if(arr[n-1] > sum) return dp[n][sum] = subsetSum(arr, sum, n-1);

    bool included = subsetSum(arr, sum - arr[n-1], n-1);
    bool not_included = subsetSum(arr, sum, n-1);

    return dp[n][sum] = (included || not_included);
}

bool equalSumPartition(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    // if the sum is odd then I cannot make a partition with two subsets having equal sum
    if(sum % 2 != 0) return false;
    sum /= 2;
    return subsetSum(arr, sum, n);
}

int countSubset(int arr[], int sum, int n){
    if(sum == 0) return 1;
    if(n == 0) return 0;

    if(arr[n - 1] > sum){
        return countSubset(arr, sum, n-1);
    }

    int included = countSubset(arr, sum - arr[n-1], n-1);
    int not_included = countSubset(arr, sum, n-1);

    return included + not_included;
}

int countSubsetTopDown(int arr[], int sum, int n){
    int solve[n+1][sum+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0) solve[i][j] = 0;
            if(j == 0) solve[i][j] = 1;
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){

            if(arr[i-1] > j){
                solve[i][j] = solve[i-1][j];
            }

            else{

                solve[i][j] = (solve[i-1][j-arr[i-1]] + solve[i-1][j]);

            }

        }
    }

    return solve[n][sum];

}

int coinChange(int arr[], int sum, int n){
    // exactly similar to count the number of subsets with given sum but since we have infinite no. of coins available it becomes the question of unbounded knapsack

    if(sum == 0) return 1;
    if(n == 0) return 0;

    if(arr[n-1] > sum){
        return coinChange(arr, sum, n-1);
    }

    int included = coinChange(arr, sum - arr[n-1], n); // unbounded knapsack
    int not_inlcuded = coinChange(arr, sum, n-1);

    return included + not_inlcuded;

}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    memset(dp, -1, sizeof(dp));
    cout<<subsetSumTopDown(arr, 9, 6)<<endl;
    int arr1[] = {1, 5, 3};
    cout<<equalSumPartition(arr1, 3)<<endl;
    int arr2[] = {0, 0, 0, 0, 1};
    cout<<countSubsetTopDown(arr2, 1, 5)<<endl;
    int arr3[] = {2, 5, 3, 6};
    cout<<coinChange(arr3, 10, 4)<<endl;
    return 0;
}