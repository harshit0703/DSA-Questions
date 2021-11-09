#include<iostream>
using namespace std;

int findPeak(int arr[], int n){             // here the main catch is that we are applying bs in an unsorted array
    int st = 0;                             
    int en = n-1;
    while(st <= en){
        int mid = st + (en - st)/2;
        if(mid > 0 && mid < n-1){
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1] > arr[mid]){
                en = mid - 1;               // the element which is greater than the mid have higher chance to be a peak 
            }else{                          // hence we will travel in that direction
                st = mid + 1;
            }
        }
        else if (mid == 0){
            if(arr[mid] > arr[mid+1]){      // at the edges only 2 element will be present and hence one of them must be a peak 
                return 0;
            }
            else return 1;
        }
        else{
            if(arr[mid] > arr[mid-1]){
                return mid;
            }
            else return mid - 1;
        }
    }
}

int main(){
    int arr[] = {5, 10, 20, 15};
    int ans = findPeak(arr, 4);     // peak element is an element which is greater than both the neighbors
    cout<<ans;
    // find max in bitonic array = peak element
    // search an element in bitonic array = peak element + break into two sorted arrays + apply binary search on both of them
    return 0;
}