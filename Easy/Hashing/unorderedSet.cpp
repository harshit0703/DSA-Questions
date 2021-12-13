#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int>s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);

    for(auto i = s.begin(); i != s.end(); i++){
        cout<<*i<<" ";
    }

    

    return 0;
}