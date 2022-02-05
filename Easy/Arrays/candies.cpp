#include<bits/stdc++.h>
using namespace std;

int distCandies(int arr[], int n){
    if(n == 1 || n == 0){
        return 1;
    }

    int candies[n];
    for(int i = 0; i < n; i++) candies[i] = 1;

    for(int i = 0; i < n - 1; i++){
        if(arr[i+1] > arr[i] && candies[i+1] <= candies[i]){
            candies[i+1] = candies[i] + 1;
        }
    }

    for(int i = n-1; i >= 1; i--){
        if(arr[i-1] > arr[i] && candies[i-1] <= candies[i]){
            candies[i-1] = candies[i] + 1;
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += candies[i];
    }

    return sum;

}

int main()
{
    int arr[] = {1, 2, 3, 4};
    cout<<distCandies(arr, 4);
    return 0;
}