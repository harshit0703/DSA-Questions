#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, b, k;
    cin>>a>>b>>k;
    int size = b + 1;
    int arr[size];
    for(int i=0; i<size; i++){
        arr[i] = 0;
    }
    for(int i = 2; i<size; i++){
        for(int j=i*i; j<size; j+=i){
            arr[j] = 1;     // marking the non prime numbers
        }
    }
    int ans;
    for(int i=2; i<size; i++){
        if(arr[i] == 0 && i >= a){
            if(k == 1){
                ans = i;
            }else{
                k--;
            }
        }
    }
    cout<<ans;
}