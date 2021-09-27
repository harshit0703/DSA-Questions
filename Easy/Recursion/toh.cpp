#include<iostream>
using namespace std;

void toh(int n, char src, char dest, char helper){
    if (n==0){
        return;
    }
    // at first we will transfer n-1 discs from a to c using b
    // then we will move the nth disc from a to b
    // then move back the n-1 discs from c to b using a
    toh(n-1, src, helper, dest);
    cout<<"Move "<<n<<" form "<<src<<" to "<<dest<<" using "<<helper<<endl;
    toh(n-1, helper, dest, src);
}

int main(){
    // tower of hanoi is a simple task where you have to transfer the discs from one tower to another keeping 2 conditions in mind i.e only smaller disc can come above a greater one and you can only move one disc at a time
    int n;
    cin>>n;
    toh(n,'A', 'B', 'C');
    return 0;
}