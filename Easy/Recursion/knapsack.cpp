#include<iostream>
using namespace std;

int knapsack(int value[], int wt[], int max_wt, int n){
    
    if (n == 0 || max_wt == 0){
        return 0;
    }

    if (wt[n-1] > max_wt){
        return knapsack(value, wt, max_wt, n-1);
    }
    // at every step you have two options either to add the item in the bag or not and check for the max output
    int included = knapsack(value, wt, max_wt - wt[n-1], n-1) + value[n-1];
    int not_included = knapsack(value, wt, max_wt, n-1);

    return max(included, not_included);
}

int main(){
    // we need to maximize the value of the objects we can accommodate if a bag of weight w.
    int value[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int max_wt = 50;

    int ans = knapsack(value, wt, max_wt, 3);
    cout<<ans;

    return 0;
}