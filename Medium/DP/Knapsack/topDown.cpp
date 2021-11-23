#include<bits/stdc++.h>
using namespace std;

int topDown(int val[], int wt[], int max_wt, int n){
    int DP[n+1][max_wt+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < max_wt+1; j++){
            if(i == 0 || j == 0){
                DP[i][j] = 0;       // initialization
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < max_wt + 1; j++){

            if(wt[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }

            else if(wt[i-1] <= j){
                int included = val[i-1] + DP[i-1][j - wt[i-1]];
                int not_included = DP[i-1][j];

                DP[i][j] = max(included, not_included);
            }

        }
    }
    
    return DP[n][max_wt];

}

int main()
{
    int val[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int max_wt = 50;            // holding capacity of the knapsack bag
    int ans = topDown(val, wt, max_wt, 3);
    cout << ans;
    return 0;
}