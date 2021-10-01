#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    // wave sort provides us with a wave like array in which every alternate element is smaller/bigger than the neighboring elements
    // TC = O(n/2)
    int arr[] = {1, 3, 4, 7, 5, 6, 2};
    int i = 1;
    while(i < 7){
        if (arr[i] > arr[i-1])
            swap(arr,i,i-1);
        
        if (arr[i] > arr[i+1] && i<=5)
            swap(arr,i,i+1);
        
        i+=2;
    }

    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}