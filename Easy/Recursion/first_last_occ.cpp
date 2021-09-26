#include<iostream>
using namespace std;

int last_occ(int arr[], int n, int key, int ans, int idx){
    if(n == 0){
        return ans;
    }
    int prev_check = last_occ(arr + 1, n - 1, key, ans, ++idx);
    if(prev_check != -1){
        return prev_check;
    }
    else if(arr[0] == key){
        return idx-1;
    }
    return -1;
}

int first_occ(int arr[], int n, int key, int idx){
    if (idx == n){
        return -1;
    }
    
    if( arr[idx] == key){
        return idx;
    }
    return first_occ(arr, n, key, idx+1);
}

int main(){
    // find the first and last occurence of a particular element inside an array using recursion
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int first = first_occ(arr, n, key, 0);
    int last = last_occ(arr, n, key, -1, 0);
    cout<<first<<" "<<last;
    return 0;
}