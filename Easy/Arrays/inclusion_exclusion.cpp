#include<iostream>
using namespace std;

int main(){
    //find the gcd = hcf using inclusion exclusion principal
    // hcf is the largest number that divides both of the given numbers
    int a,b;
    cin>>a>>b;
    while(b != 0){
        int rem = a % b;
        a = b;
        b = rem;
    }
    cout<<a;
    return 0;
}