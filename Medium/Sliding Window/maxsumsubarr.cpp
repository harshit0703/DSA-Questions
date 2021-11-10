#include<iostream>
#include<algorithm>
using namespace std;

void maxSumSubArr(int arr[], int n, int k){
    int sum = 0;
    int ans;
    int st = 0;
    for(int i=0; i<k; i++){
        sum += arr[i];          //this will store the sum of the first window
    }
    
    ans = sum;

    for(int i=k; i<n; i++){
        sum -= arr[st++];
        sum += arr[i];          // now we will keep subtracting the first element and moving the window to the end and 
        ans = max(sum, ans);    // updating our answer  TC = O(n)
    }
    cout<<ans;
}

int main(){
    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    int k = 3;
    maxSumSubArr(arr, 7, k);
    return 0;
}