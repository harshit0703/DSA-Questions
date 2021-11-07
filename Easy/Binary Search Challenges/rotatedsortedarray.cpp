#include<iostream>
using namespace std;

int sortedArrayRotations(int arr[], int n){
    int st = 0;
    int en = n-1;

    while(st <= en){
        int mid =  st + (en-st)/2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if(arr[mid] <= prev && arr[mid] <= next){
            return mid;
        }
        else if(arr[st] <= arr[mid]){
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
}

int main(){
    int arr[] = {40, 50, 10, 20, 30};
    int ans = sortedArrayRotations(arr, 5);
    cout<<ans;
    return 0;
}