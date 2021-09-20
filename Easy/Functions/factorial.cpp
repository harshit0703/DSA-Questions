#include <iostream>
using namespace std;

void print_fact(int n){
    int fact = 1;
    while(n>0){
        fact *= n;
        n--;
    }
    cout<<fact;
}

int main()
{
    //factorial is the product of n natural nos form the number to 1.
    int n;
    cin>>n;
    print_fact(n);
    return 0;
}