#include<iostream>
#include<algorithm>
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
           en = mid - 1;        
       }
       else{
           res = arr[mid];          // since arr[mid] is smaller than the key it is a possible contender for floor
           st = mid + 1;
       }
    }
    return res;
}

int findCeil(int arr[], int n, int key){
    int st = 0;
    int en = n-1;
    int res = -1;
    while(st <= en){
        int mid = st + (en - st)/2;
        if(arr[mid] == key){
            res = arr[mid];
            break;
        }
        else if(key < arr[mid]){
            res = arr[mid];         // since arr[mid] is greater than the key it is a possible contender for ceil
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return res;
}

int binarySearch(int arr[], int n, int key){
    int st = 0;
    int en = n-1;
    int res = -1;

    while(st <= en){
        int mid = st + (en - st)/2;
        if(arr[mid] == key){
            return 0;
        }
        else if(key < arr[mid]){
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    int ceil = arr[st];             // if we observe carefully there is no need to find ceil and floor seperately as at the end 
    int flr = arr[en];              // the st and en are pointing to the ceil and flr themselves :)
    res = min(key-flr, ceil-key);
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 11, 19};
    int flr = findFloor(arr, 9, 5);
    int ceil = findCeil(arr, 9, 5);
    int ans = min(5-flr, ceil-5);   // the min diff element will be the min diff between ceil and floor
    int res = binarySearch(arr, 9, 5);
    cout<<ans<<" "<<res;
    return 0;
}