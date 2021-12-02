#include<bits/stdc++.h>
using namespace std;

int minCoinChange(int coin[], int sum, int n){
    int DP[n+1][sum+1];
    // the initialization of this particular question is what makes it so special
    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++){
            
            if(j == 0){
                DP[i][j] = 0;
            }

            if(i == 0){
                DP[i][j] = INT_MAX - 1;
            }

            if(i == 1){ // this is the special case we also need to initialize the 2nd row for single coin
                if(j % coin[i] == 0){
                    DP[i][j] = 1;
                }
                else{
                    DP[i][j] = INT_MAX - 1;
                }
            }

        }
    }

    for (int i = 2; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++){

            if(coin[i-1] > sum){
                DP[i][j] = DP[i-1][j];
            }

            else{
                DP[i][j] = min(DP[i-1][j], DP[i][j-coin[i-1]] + 1);
            }

        }
    }
    
    return DP[n][sum];

}

int main()
{
    // we need to find the minimum number of coins to reach the sum and can use the coins repeatedly
    int coin[] = {1, 2, 3};
    int sum = 5;
    int ans = minCoinChange(coin, sum, 3);
    cout<<ans;
    return 0;
}