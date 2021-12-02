#include<bits/stdc++.h>
using namespace std;

int maxCoinChange(int coin[], int sum, int n){
    int DP[n+1][sum+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++){
            if(i == 0){ 
                DP[i][j] = 0;
            }
            if(j == 0){
                DP[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++){

            if(coin[i-1] > j){
                DP[i][j] = DP[i-1][j];
            }
            
            else{
                DP[i][j] = DP[i - 1][j] + DP[i][j - coin[i - 1]]; // since we need to find the total ways we will add all choices
            }
            
        }
    }
    
    return DP[n][sum];

}

int main()
{
    int coin[] = {1, 2, 3};
    int sum = 5;
    int ans = maxCoinChange(coin, sum, 3);
    cout<<ans;
    return 0;
}