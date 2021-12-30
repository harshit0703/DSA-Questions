#include<bits/stdc++.h>
using namespace std;

void permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i = 0; i < str.length(); i++){
        char fix = str[i];
        string prev = str.substr(0, i);
        string next = str.substr(i + 1); // in case of out of index it will automatically take in an empty string
        permutation(prev + next, fix + ans);
    }
}

int countPaths(int st, int en){
    if(st > en){
        return 0;
    }
    if(st == en){
        return 1;
    }
    int ans = 0;
    for(int i = 1; i <= 6; i++){
        ans += countPaths(st + i, en);
    }
    return ans;
}

int countPathsMaze(int n, int row, int col){
    if(row >= n || col >= n){
        return 0;
    }
    if(row == n-1 && col == n-1){
        return 1;
    }
    int moveFwd = countPathsMaze(n, row, col+1);
    int moveDwn = countPathsMaze(n, row+1, col);
    return moveFwd + moveDwn;
}

int knapsack(int val[], int wt[], int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }
    if(wt[n-1] > W){
        return knapsack(val, wt, W, n-1);
    }
    int included = knapsack(val, wt, W - wt[n-1], n-1) + val[n-1];
    int notIncluded = knapsack(val, wt, W, n-1);
    return max(included, notIncluded);
}

int tiling(int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1; // only vertical case is possible
    }

    // since we have a board of 2 x n and tile of 2 x 1 we have two ways of placing the tile ie horizontal and vertical
    // catch is if placed horizontal the other tile must be placed horizontally only

    int horizontal = tiling(n-2);
    int vertical = tiling(n-1);
    return horizontal + vertical;
}

int friendsPair(int n){
    if(n == 0 || n == 1 || n == 2){
        return n;
    }

    return friendsPair(n-1) + friendsPair(n-2) * (n - 1);
}

int main()
{
    string str = "ABC";
    // permutation(str, "");
    // cout<<countPaths(1, 4);
    // cout<<countPathsMaze(3, 0, 0);
    int val[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int W = 50; // capacity of the knapsack
    // cout<<knapsack(val, wt, W, 3);
    // cout<<tiling(4);
    cout<<friendsPair(4);

    return 0;
}