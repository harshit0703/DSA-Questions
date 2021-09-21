#include<iostream>
using namespace std;

int binary_search(int arr[], int size, int key){
    int low = 0;
    int high = size - 1;
    while(low<=high){
        int mid = low+high / 2;
        if (key == arr[mid]){
            return mid;
        }else if (key < arr[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    // binary search is a more simpler and more efficient way of searching in an array as it breaks down the array after each iteration
    // TC = O(logn)

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;
    int ans = binary_search(arr, n, key);
    if(ans == -1 ){
        cout<<"element not found.";
    }else{
        cout<<"element found at index:"<<ans;
    }
    return 0;
}