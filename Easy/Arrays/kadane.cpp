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
    int currsum = 0;
    int maxsum = 0;
    
    for(int i=0; i<n; i++){
        currsum += arr[i];
        if (currsum < 0){
            currsum = 0;
        }
        maxsum = max(currsum, maxsum);
    }

    cout<<maxsum;
    
    return 0;
}