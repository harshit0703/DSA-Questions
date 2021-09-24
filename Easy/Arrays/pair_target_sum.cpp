#include<iostream>
using namespace std;

int main(){
    // we need to check if there exist a pair of elements which meets a required sum with a two pointer approach
    // for this approach the array must be in a sorted order
    // TC = O(n)
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target_sum;
    cin>>target_sum;
    int start = 0, end = n-1, flag = 0;
    while(start <= end){
        if(target_sum == arr[start] + arr[end]){
            cout<<start<<" "<<end;
            flag = 1;
            break;
        }else if (target_sum > arr[start] + arr[end]){
            start++;
        }else{
            end--;
        }
    }
    if (flag == 0){
        cout<<"target sum cannot be achieved with the given array.";
    }
    return 0;
}