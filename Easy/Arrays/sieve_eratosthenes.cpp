#include<iostream>
using namespace std; 

int main(){
    // this algorithms helps to find the prime nos in a particular range more efficiently
    // TC = O(n log log n)
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = 0;
    }

    for(int i=2; i<n+1; i++){
        for(int j=i*i; j<=n+1; j+=i){
            arr[j] = 1;
        }
    }

    for(int i=2; i<n+1; i++){
        if (arr[i] == 0){
            cout<<i<<" ";
        }
    }

    return 0;
}