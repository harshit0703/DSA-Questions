#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    //armstrong number is the one in which sum of cubes of individual dig is equal to the number itself
    int n;
    cin>>n;
    int num = n;
    int sum = 0;
    while(num>0){
        int dig = num%10;
        sum += pow(dig,3);
        num = num/10;
    }
    if (sum == n){
        cout<<"It is an armstrong number.";
    }else{
        cout<<"Not an armstrong number.";
    }
    return 0;
}