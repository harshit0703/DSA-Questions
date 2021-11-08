#include<iostream>
#include<algorithm>
using namespace std;

int minIdx(int arr[], int n){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = st + (en-st)/2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
            return mid;
        }
        else if( arr[st] <= arr[mid]){
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
}

int binarySearch(int arr[], int st, int en, int key){
    while(st <= en){
        int mid = st + (en-st)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
    return -1;
}

int findElement(int arr[], int n, int key){
    int minidx = minIdx(arr, n);            // at first we found the idx of the min element in the array and then divide it into
    if(minidx == -1){                       // two sorted arrays and applied bs on each of them seperateley
        return -1;
    }

    int left = binarySearch(arr, 0, minidx-1, key);
    int right = binarySearch(arr, minidx, n-1, key);

    if(left == -1 && right == -1){
        return -1;
    }
    else{
        return (left == -1)?right:left;
    }
}

int main(){
    int arr[] = {11, 12, 16, 18, 2, 5, 6, 8};
    int ans = findElement(arr, 8, 16);
    cout<<ans;
    return 0;
}