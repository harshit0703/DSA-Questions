#include<bits/stdc++.h>
using namespace std;

int DP[100][1000];  // size of the matrix is dependent on the elements that are bound to change in recursion

int knapsack(int val[], int wt[], int max_wt, int n){

    if(n == 0 || max_wt == 0){
        return 0;
    }

    if(DP[n][max_wt] != -1){
        return DP[n][max_wt];       // by doing this we are tackling the overlapping cases
    }

    if(wt[n-1] > max_wt){
        return DP[n][max_wt] = knapsack(val, wt, max_wt, n-1);
    }

    int included = knapsack(val, wt, max_wt - wt[n-1], n-1) + val[n-1];
    int not_included = knapsack(val, wt, max_wt, n-1);

    return DP[n][max_wt] = max(included, not_included);

}

int main()
{
    int val[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int max_wt = 50; // holding capacity of the knapsack bag
    memset(DP, -1, sizeof(DP)); // this function can only be called inside another function just like other stl
    int ans = knapsack(val, wt, max_wt, 3);
    cout << ans;
    return 0;
}