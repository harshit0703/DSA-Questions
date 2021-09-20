#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    while(n>0){
        fact *= n;
        n--;
    }
    return fact;
}

int main()
{
    // pascal's triangle is a pattern of binomial cofficients
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int ele = factorial(i) / (factorial(j) * factorial(i-j));
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}