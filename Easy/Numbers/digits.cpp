#include <iostream>
using namespace std;

int main()
{
    //print the digits of the number from right to left
    int n;
    cin>>n;
    while(n>0){
        int dig = n%10;
        n= n/10;
        cout<<dig<<endl;
    }
    return 0;
}