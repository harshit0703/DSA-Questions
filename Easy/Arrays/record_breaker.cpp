#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //we need to print the record breaking days according to the constraints
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>n;
    }

    //a day is record breaking if:
    //visitors is greater than any of the previous days
    //visitors on the current day is larger than the following day

    int max_vis = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(i == n-1 && arr[i] > max_vis){
            ans++;
        }
        else if(arr[i] > max_vis && arr[i] > arr[i+1]){
            ans++;
        }
        max_vis = max(max_vis, arr[i]);
    }
    cout<<ans;
    return 0;
}