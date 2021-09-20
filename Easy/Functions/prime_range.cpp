#include <iostream>
using namespace std;

void find_prime(int a, int b){
    int flag = 0;
    for(int i=a; i<=b; i++){
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            cout<<i<<endl;
        }
        flag = 0;
    }
}

int main()
{
    //find all the prime numbers between a given range of numbers
    int a,b;
    cin>>a>>b;
    find_prime(a,b);
    return 0;
}