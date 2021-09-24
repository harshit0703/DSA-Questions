#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    // form the biggest number from the given string
    string str;
    cin>>str;
    sort(str.begin(), str.end(), greater<int>());
    cout<<str;
    return 0;
}