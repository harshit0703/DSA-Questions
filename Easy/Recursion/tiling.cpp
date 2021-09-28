#include<iostream>
using namespace std;

int tiling_ways(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    int count = 0;
    count += tiling_ways(n - 1) + tiling_ways(n - 2);
    return count;
}

int main(){
    // we need to calculate the number of ways to tile the floor with 1x2 and 1x1 tiles we will be given with a square floor with nxn dimension
    int n; 
    cin>>n;
    int ans = tiling_ways(n);
    cout<<ans;
    return 0;
}