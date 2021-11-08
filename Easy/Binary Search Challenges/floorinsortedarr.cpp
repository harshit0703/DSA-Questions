#include<iostream>
using namespace std;

int findFloor(int arr[], int n, int key){
    int res = -1;
    int st = 0;
    int en = n-1;

    while(st <= en){
       int mid = st + (en - st)/2;
       if(arr[mid] == key){
           res = arr[mid];
           break;
       }
       else if(key < arr[mid]){
           en = mid - 1;            // if you want to find  the ceil then the result will be updated here
       }
       else{
           res = arr[mid];
           st = mid + 1;
       }
    }
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 11, 19};
    int ans = findFloor(arr, 9, 5);
    cout<<ans;
    return 0;
}