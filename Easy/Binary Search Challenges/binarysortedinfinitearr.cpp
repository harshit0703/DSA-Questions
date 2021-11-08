#include<iostream>
using namespace std;

int firstocc(int arr[], int st, int en, int key){
    int res = -1;
    while(st <= en){
        int mid = st + (en - st)/2;     // this question is simply a variation as we know how to find an element in an infinite arr
        if(arr[mid] == key){            // and we also know how to find first occ in a sorted arr 
            res = mid;
            en = mid - 1;
        }
        else if(key < arr[mid]){
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return res;
}


int findele(int arr[], int key){
    int st = 0;
    int en = 1;             // the main challenge in an infinite array is to find where to place the en pointer

    while(arr[en] < key){
        st = en;
        en = en*2;          // through this process we will create a finite sorted subarray containing the key
    }

    int res = firstocc(arr, st, en, key);
    return res;
}


int main(){
    int arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};   // considering this to be an infinite array
    int ans = findele(arr, 1);
    cout<<ans;
    return 0;
}