#include<iostream>
using namespace std;

int kadane(int arr[], int n, int cdn){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum < 0 && cdn == 1){
            // this condition is for all positive elements
            sum = 0;
        }else if(sum > 0 && cdn == -1){
            // this condition is for all negative elements
            sum = 0;
        }
    }
    return sum;
}

int main(){
    // a circular subarray case is also possible in that case we simply multiply the whole array by -1 get the min sum and subtract it from the max sum subarray

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int nonwrapsum = kadane(arr, n, 1);
    int totalsum = 0;
    for(int i=0; i<n; i++){
        totalsum += arr[i];
        arr[i] *= -1;
    }

    int wrapsum = totalsum + kadane(arr, n, -1);

    cout<<wrapsum<<" "<<nonwrapsum;

    return 0;
}