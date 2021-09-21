#include<iostream>
#include<climits>
using namespace std;

int main(){
    //print the max and min element in the array
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i<n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
        if (arr[i] < min){
            min = arr[i];
        }
    }

    cout<<max<<endl<<min;

    return 0;
}