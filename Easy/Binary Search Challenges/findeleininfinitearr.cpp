#include<iostream>
using namespace std;

int binarySearch(int arr[], int st, int en, int key){
    while(st <= en){
        int mid = st + (en - st)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key < arr[mid]){
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return -1;
}


int findele(int arr[], int key){
    int st = 0;
    int en = 1;             // the main challenge in an infinite array is to find where to place the en pointer

    while(arr[en] < key){
        st = en;
        en = en*2;          // through this process we will create a finite sorted subarray containing the key
    }

    int res = binarySearch(arr, st, en, key);
    return res;
}


int main(){
    int arr[] = {1, 3, 4, 5, 6, 7, 8, 9, 10};   // considering this to be an infinite array
    int ans = findele(arr, 7);
    cout<<ans;
    return 0;
}