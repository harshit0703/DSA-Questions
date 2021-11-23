#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n){

    bool DP[n+1][sum+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++){
            if(i == 0){
                DP[i][j] = false;
            }
            if(j == 0){
                DP[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++){
            
            if(arr[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }

            else if (arr[i-1] <= j){
                
                bool included = DP[i-1][j - arr[i-1]];
                bool not_included = DP[i-1][j];

                DP[i][j] = included || not_included;

            }

        }
    }
    
    return DP[n][sum];

}

int main()
{
    int arr[] = {2, 3, 7, 5, 8};
    int sum = 11;
    cout<<subsetSum(arr, sum, 5);
    return 0;
}