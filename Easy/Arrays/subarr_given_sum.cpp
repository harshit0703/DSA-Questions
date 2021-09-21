#include <iostream>
using namespace std;

int main()
{
    //we need to find a subarr which adds to a given sum by the user
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;

    int test = sum;
    int i=0, j=0;
    
    while(test!=0){
        if(test>0){
            test -= arr[j];
            j++;
        }else if(test<0){
            test += arr[i];
            i++;
        }
    }

    cout<<i<<" "<<j-1;

    return 0;
}