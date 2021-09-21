#include<iostream>
using namespace std;

int main(){
    //find the smallest positive missing number in the array in O(1) time.
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int i=0;
    while(i<n){
        if(arr[i] > 0 ){
            cout<<i;
            break;
        }
        i++;
    }

    return 0;
}