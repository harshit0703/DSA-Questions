#include<bits/stdc++.h>
using namespace std;

vector<int>subsetSum(int arr[], int sum, int n){
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

            DP[i][j] = DP[i-1][j] || DP[i-1][j - arr[i-1]];
        }
    }
    
    // the last row of dp will contain all the possible subsets that can be made with the full array available

    vector<int>ans;
    for(int j = 0; j <= sum/2; j++){
        if(DP[n][j]){
            ans.push_back(j);
        }
    }

    return ans;

}

int main()
{
    int arr[] = {1, 5, 11, 6};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += arr[i];
    }
    vector<int> possible_values = subsetSum(arr, sum, 4);

    int ans = INT_MAX;

    for(auto i : possible_values){
        ans = min(ans, sum - 2*i);
    }

    cout<<ans;

    return 0;
}