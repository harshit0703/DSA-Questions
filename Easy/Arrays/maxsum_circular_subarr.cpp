#include<iostream>
using namespace std;

int kadane(int arr[], int n){
    int currSum = 0;
    int maxSum = 0;
    for(int i = 0; i < n; i++){
        currSum += arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

int kadaneWrap(int arr[], int n){
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
        arr[i] *= -1;
    }
    int nonWrapSum = kadane(arr, n);
    return totalSum + nonWrapSum;
}

int main(){
    // a circular subarray case is also possible in that case we simply multiply the whole array by -1 get the min sum and subtract it from the max sum subarray

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int nonwrapsum = kadane(arr, n);

    int wrapsum = kadaneWrap(arr, n);

    cout<<wrapsum<<" "<<nonwrapsum;

    return 0;
}