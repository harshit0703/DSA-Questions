#include<iostream>
using namespace std;

// TC = O(n)

int make_pairs(int n){
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    // at each case we have two options either to pair a person on not
    int ans = 0;
    ans += make_pairs(n-1); // if we did not make a pair
    ans += make_pairs(n-2) * (n-1); // if we made a pair 
    // since every person is different we will have n-1 differnt persons for every nth person to choose a partner from
    return ans;
}   

int main(){
    // we have to pair up n number of friends
    int n;
    cin>>n;
    int ans = make_pairs(n);
    cout<<ans;
    return 0;
}