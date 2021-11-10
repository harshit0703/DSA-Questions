#include<iostream>
#include<climits>
using namespace std;

bool isValid(int arr[], int n, int maxTime, int k){
    int count = 1;
    int totalTime = 0;

    for(int i=0; i<n; i++){
        totalTime += arr[i];
        if(totalTime > maxTime){
            count++;
            totalTime = arr[i];         // if total time exceeds the given maxtime we need to add another painter
        }
    }
    if(count == k){
        return true;
    }
    return false;
}

int findTime(int arr[],int n, int k){
    // the binary search will start from the max time to the sum of all the time
    int maxele = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxele){
            maxele = arr[i];
        }
        sum += arr[i];
    }

    int st = maxele;
    int en = sum;
    int res = -1;

    while(st <= en){
        int mid = st + (en - st)/2;
        if(isValid(arr, n, mid, k)){
            res = mid;
            en = mid - 1;       // if we found a valid time we need to minimize it by moving to the left
        }
        else{
            st = mid + 1;       // if valid time is not found we need to move to the right
        }
    }
    return res;
}

int main(){
    // this problem is an exact copy of the page allocation problem just instead of pages we are given the time to paint a board
    // and painters instead of students
    // we need to minimize the max amount of time to paint all the boards 
    int arr[] = {10, 20, 30, 40};
    int k = 2;
    int ans = findTime(arr, 4, k);
    cout<<ans;
    return 0;
}