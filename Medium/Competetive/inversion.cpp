#include<iostream>
using namespace std;

long long merge(int arr[], int st, int mid, int en){
    int n1 = mid - st + 1;
    int n2 = en - mid;
    int a[n1], b[n2]; // temp arrays
    for(int i=0; i<n1; i++){
        a[i] = arr[st + i];
    }
    for(int i=0; i<n2; i++){
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    long long inversion_cnt = 0;
    
    while( i<n1 && j<n2){
        if (a[i] >= b[j]){
            arr[k] = b[j];
            j++;
            k++;
        }else{
            inversion_cnt += n2 - j;
            arr[k] = a[i];
            i++;
            k++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }

    return inversion_cnt;

}

long long merge_sort(int arr[], int st, int en){
    long long inversion_cnt = 0;
    if(st < en){
        int mid = (st + en) / 2;
        inversion_cnt += merge_sort(arr, st, mid);
        inversion_cnt += merge_sort(arr, mid+1, en);
        inversion_cnt += merge(arr, st, mid, en);
    }
    return inversion_cnt;
}

int main(){
    // in an array if an a[i] exist which is smaller than a[j] for every j > i then this pair is reffered to as an inversion pair

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // brute force approach
    // int inversion_cnt = 0;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if (arr[j] > arr[i]){
    //             inversion_cnt++;
    //         }
    //     }
    // }
    // cout<<inversion_cnt;
    // TC = O(n^2)

    // More efficient approach includes the use of merge sort as we merge the arrays in the final step we know that both the arrays are previously sorted hence if an element is greater than our current element than all the elements in the other array will be greater than this current element and hence the number of inversions will be incremented accordingly
    // TC = O(nlogn)

    int ans = merge_sort(arr, 0, n-1);
    cout<<ans;

    return 0;
}