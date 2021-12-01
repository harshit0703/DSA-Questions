#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int val[], int wt[], int W, int n){
    int DP[n+1][W+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < W+1; j++){
            if(i == 0 || j == 0){
                DP[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < W+1; j++){
            
            if(wt[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }

            int included = DP[i][j - wt[i-1]] + val[i-1];
            int not_included = DP[i-1][j];
            DP[i][j] = max(included, not_included);
        }
    }
    
    return DP[n][W];

}

int main()
{
    int val[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int W = 50;
    int ans = unboundedKnapsack(val, wt, W, 3);
    cout<<ans;
    return 0;
}