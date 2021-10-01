#include<iostream>
#include<climits>
using namespace std; 

int main(){
    // count sort works on the duplicacy of the elemets in the given array
    // TC = O(n) but not effecient for larger size of the array
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int max_ele = INT_MIN;
    for(int i=0; i<9; i++){
        if(max_ele < arr[i]){
            max_ele = arr[i];
        }
    }

    int element_count[10] = {0};
    for(int i=0; i<9; i++){
        element_count[arr[i]]++;
    }

    for(int i=1; i<=max_ele; i++){
        element_count[i] += element_count[i-1];
    }

    int ans[9];
    for(int i=8; i>=0; i--){
        int element = arr[i];
        int idx = --element_count[element];
        ans[idx] = element;
    }

    for(int i=0; i<9; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}