#include<iostream>
using namespace std;

int main(){
    //give the prime factorization of the number using sieve of eratosthenes
    int n;
    cin>>n;
    int arr[n+1] = {0};

    for(int i=2; i<=n; i++){
        for(int j=i*i; j<=n; j+=i){
            arr[j] = 1;
        }
    }

    int i=2;
    while(n > 1){
        if (n % i == 0 && arr[i] == 0){
            n /= i;
            cout<<i<<" ";
            i =2;
        }else{
            i++;
        }
    }

    return 0;
}