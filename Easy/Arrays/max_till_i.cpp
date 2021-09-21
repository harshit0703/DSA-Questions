#include<iostream>
#include<climits>
using namespace std;

int main(){
    // print max element for each iteration by keeping a check of the previous max and comparing it to the current element
    // TC = O(n)
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int max = INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        cout<<max<<" ";
    }

    return 0;
}