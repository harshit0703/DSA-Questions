#include<iostream>
#include<climits>
using namespace std;

int main(){
    //in selection sort we find  the min element in the array and swap it with the first element and then keep decreasing the size of the array by 1
    // TC = O(n^2)

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
   for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++){
           if(arr[i] > arr[j]){
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
   }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}