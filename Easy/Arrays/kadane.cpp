#include<iostream>
using namespace std;

int main(){
    // kadane's algo is used to find the max subarray sum in O(n) time.
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int maxsum = 0;
    
    for(int i=0; i<n; i++){
        maxsum += arr[i];
        if (maxsum < 0){
            maxsum = 0;
        }
    }

    cout<<maxsum;
    
    return 0;
}