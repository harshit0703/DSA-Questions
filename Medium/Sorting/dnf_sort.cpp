#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    // in dnf sort only 0,1,2 are the elements that are present in the array it is based on simple 3 pointer technique
    // TC = O(n) but can only work with 3 different elements
    int arr[] = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    int low = 0;
    int mid = 0;
    int high = 9;
    while(mid < high){
        if (arr[mid] == 1){
            mid++;
        }else if(arr[mid] == 0){
            swap(arr, mid, low);
            low++;
            mid++;
        }else{
            swap(arr, mid, high);
            high--;
        }
    }
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}