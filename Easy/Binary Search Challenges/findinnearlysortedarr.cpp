#include<iostream>
using namespace std;

int findElement(int arr[], int n, int key){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = st + (en - st)/2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[prev] == key){
            return prev;
        }
        else if(arr[next] == key){
            return next;
        }
        else if(key > arr[mid]){
            st = mid + 2;
        }
        else{
            en = mid - 2;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5, 10, 30, 20, 40};        // in a nearly sorted array element can be present at ith, (i-1)th and (i+1)th position
    int ans = findElement(arr, 5, 20);
    cout<<ans;
    return 0;
}