#include<iostream>
#include<climits>
using namespace std;

bool isValid(int arr[], int n, int pages, int k){
    if(k > n) return false;

    int sum = 0;
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > pages){
            return false;
        }

        if(sum + arr[i] > pages){
            sum = arr[i];
            ans++;
            if(ans > k)return false;
        }

        sum += arr[i];
    }

    return true;
}

int allocatePages(int arr[], int n, int k){
    // we need to apply binary search 
    // the st = max of the array and en = sum of all elements
    int maxele = INT_MIN;
    int sum = 0;
    int res = -1;
    for(int i=0; i<n; i++){
        if(arr[i] > maxele){
            maxele = arr[i]; 
        }
        sum += arr[i];
    }

    int st = maxele;
    int en = sum;

    while(st <= en){
        int mid = st + (en - st)/2;
        if(isValid(arr, n, mid, k)){
            res = mid;
            en = mid - 1;
        }else{
            st = mid + 1;
        }           
    }

    return res;
}

int main(){
    // we will be given with an array of book pages and a number of students to whom we need to alot these books such that 
    // the max pages held by any student is min (to balance the load among them)
    int arr[] = {5, 7, 100, 11};       // this array may or may not be sorted
    int k = 4;                          // no of students
    int ans = allocatePages(arr, 4, k);
    cout<<ans;
    return 0;
}