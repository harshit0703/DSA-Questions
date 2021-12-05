#include<bits/stdc++.h>
using namespace std;
int DP[1001][1001];

int mcm(int arr[], int i, int j){
    
    if(i >= j){
        return 0;   // base condition
    }

    if(DP[i][j] != -1){
        return DP[i][j];        // prevent overlapping cases
    }

    int ans = INT_MAX;

    for(int k = i; k <= j-1; k++){
        int temp1 = mcm(arr, i, k);
        int temp2 = mcm(arr, k+1, j);
        int extraCost = arr[i-1] * arr[k] * arr[j];
        int tempAns = temp1 + temp2 + extraCost;
        ans = min(ans , tempAns);
    }

    return DP[i][j] = ans;      // keep storing values inside the table

}

int main()
{
    memset(DP, -1, sizeof(DP));
    int arr[] = {40, 20, 30, 10, 30};
    int ans = mcm(arr, 1, 4); 
    cout<<ans;
    return 0;
}