#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int max_wt, int n){

    if(max_wt == 0 || n == 0){
        return 0;   // once the knapsack is full or no items are left there is nothing to add
    }

    if(wt[n-1] > max_wt){
        // then we only have one option to not include this item
        return knapsack(val, wt, max_wt, n-1);
    }

    // at every stage we have 2 options either to include the item in the knapsack or not

    int included = knapsack(val, wt, max_wt - wt[n-1], n-1) + val[n - 1];
    int not_included = knapsack(val, wt, max_wt, n-1);

    return max(included, not_included);
}

int main()
{
    int val[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int max_wt = 50;        // holding capacity of the knapsack bag
    int ans = knapsack(val, wt, max_wt, 3);
    cout<<ans;
    return 0;
}