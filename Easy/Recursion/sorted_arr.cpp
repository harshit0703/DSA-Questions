#include<iostream>
using namespace std;

bool check_sorted(int arr[], int n){
    if(n == 1){
        return true;
    }
    // we need to check if the first element is smaller than the next one and leave the rest to the recursion
    bool ans = check_sorted(arr + 1, n-1);
    return (arr[0] < arr[1] && ans);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bool ans = check_sorted(arr, n);
    cout<<ans;
    return 0;
}