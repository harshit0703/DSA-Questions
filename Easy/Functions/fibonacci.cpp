#include <iostream>
using namespace std;

void print_fibonacci(int n){
    int a = 0, b=1;
    for(int i=1; i<=n; i++){
        cout<<a<<endl;
        int c = a+b;
        a = b;
        b = c;
    }
}

int main()
{
    //fibonacci series is a special series in which the first two elements are always fixed i.e 0 and 1 and the remaining elements are the sum of the previous two
    int n;
    cin>>n;
    print_fibonacci(n);
    return 0;
}