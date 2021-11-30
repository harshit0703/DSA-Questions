#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int sum, int n){
    int DP[n+1][sum+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum + 1; j++){
            if(i == 0){
                DP[i][j] = 0;
            }
            if(j == 0){
                DP[i][j] = 1;       // null subset
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum + 1; j++){

            if(arr[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }

            DP[i][j] = DP[i-1][j] + DP[i-1][j-arr[i-1]];

        }
    }
    
    return DP[n][sum];

}

int main()
{
    int arr[] = {2, 3, 5, 8, 10};
    int ans = countSubsetSum(arr, 10, 5);
    cout<<ans;
    return 0;
}