#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //array in which the diff btw the consecutive elements is equal is an arithmetic array
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = 2, curr_len = 2;
    int diff = arr[0] - arr[1];
    for(int i=1; i<n-1; i++){
        int curr_diff = arr[i] - arr[i+1];
        if(curr_diff == diff){
            curr_len++;
            ans = max(curr_len, ans);
        }else{
            curr_len = 2;
            diff = arr[i] - arr[i-1];
        }

    }
    cout<<ans;
    return 0;
}