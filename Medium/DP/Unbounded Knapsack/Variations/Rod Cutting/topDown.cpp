#include<bits/stdc++.h>
using namespace std;

int rodCuts(int length[], int price[], int N, int n){
    int DP[n+1][N+1];
    
    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < N+1; j++){
            if(i == 0 || j == 0){
                DP[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < N+1; j++){
            
            if(length[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }

            else{

                int cutRod = DP[i][j - length[i - 1]] + price[i - 1]; // since we can make unlimited cuts same lenght can repeat
                int notCutRod = DP[i - 1][j];

                DP[i][j] = max(cutRod, notCutRod);
            }
        }
    }
    
    return DP[n][N];
    // hence rod cutting = unbounded knapsack
}

int main()
{
    // the idea is to maximize the profits and we can make unlimited cuts in the rod
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8}; // the lenght array may sometime not be present and we need to declare ourself
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = 8;      // the length of the rod

    int ans = rodCuts(length, price, N, N);     // the last N represent the size of the array
    cout<<ans;

    return 0;
}