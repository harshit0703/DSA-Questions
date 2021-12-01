#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int val[], int wt[], int W, int n){
    if(W==0 || n==0){
        return 0;
    }

    if(wt[n-1] > W){
        return unboundedKnapsack(val, wt, W, n-1);
    }

    int included = unboundedKnapsack(val, wt, W-wt[n-1], n) + val[n-1]; 
    int not_included = unboundedKnapsack(val, wt, W, n-1);

    return max(included, not_included);

}

int main()
{
    // in unbounded knapsack the repetition of items is allowed hence if we like an item we can add it number of times and if we
    // chose to not included we will not included in any further case
    int val[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int W = 50;
    int ans = unboundedKnapsack(val,wt, W, 3);
    cout<<ans;
    return 0;
}