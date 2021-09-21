#include<iostream>
using namespace std;

int main(){
    //the main idea is to keep a bigger array and put the current element of the smaller array in the index of the bigger array so as soon as you find an element already present in the bigger array your job is done :)
    // TC = O(n)

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    const int big_size = 1e3;
    int big_arr[big_size];
    for(int i=0; i<big_size;i++){
        big_arr[i] = 0;
    }

    for(int i=0; i<n; i++){
        if(big_arr[arr[i]] != 0){
            cout<<big_arr[arr[i]];
            break;
        }else{
            big_arr[arr[i]] = i;
        }
    }

    return 0;
}