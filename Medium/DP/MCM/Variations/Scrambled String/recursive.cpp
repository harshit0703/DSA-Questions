#include<bits/stdc++.h>
using namespace std;

bool scrambledStr(string a, string b){

    if(a.compare(b) == 0){
        return true;
    }

    if(a.length() <= 0){
        return false;
    }

    bool flag = false;

    for(int i = 1; i < a.length(); i++){

        // we simply breaked the problem into two conditions one for swapping and other for not swapping
        // swapping = compare the opposite parts of the strings
        // not swapping = compare the same parts of the strings
        // if either of them is true the ans is true otherwise false

        if((a.substr(0, i) == b.substr(i+1) && a.substr(i) == b.substr(0, a.length()-i)) || 
        (a.substr(0, i) == b.substr(0, i) && a.substr(i) == b.substr(i))){
            flag = true;
            break;
        }

    }

    return flag;

}

int main()
{
    string a, b;
    cin>>a>>b;
    if(a.length() != b.length()){
        return -1;
    }

    cout<<scrambledStr(a, b);

    return 0;
}