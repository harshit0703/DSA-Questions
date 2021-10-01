#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r){

    int pi = arr[r];  // taking the last element as the pivot point
    int i = l-1;
    int j = l;

    while(j < r){
        if(arr[j] < pi){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r); // this will be the suitable position for the pivot element
    return i+1;

}

void quick_sort(int arr[], int l, int r){
    if(l < r){
        int pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);
    }
}

int main(){
    // the main idea behind quick sort is to put break the array in two parts along pivot element and place the pivot at its respective position in the array
    // TC = O(nlogn) avg time,  worst case O(n^2)
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quick_sort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}