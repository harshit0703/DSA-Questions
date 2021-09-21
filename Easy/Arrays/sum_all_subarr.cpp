#include <iostream>
using namespace std;

int main()
{
    //we need to print the sum of all the subarrays
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[n];
    }
    
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            cout<<sum<<endl;
        }
    }

    return 0;
}