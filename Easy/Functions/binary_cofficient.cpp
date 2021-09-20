#include <iostream>
using namespace std;

int fact(int n){
    int factorial = 1;
    while(n>0){
        factorial *= n;
        n--;
    }
    return factorial;
}

void print_binary_coff(int n, int r){
    int nCr = fact(n)/(fact(r) * fact(n-r));
    cout<<nCr;
}

int main()
{
    //nCr
    int n,r;
    cin>>n>>r;
    print_binary_coff(n,r);
    return 0;
}