#include<bits/stdc++.h>
using namespace std;

void printReverse(string str){
    if(str.length() == 0){
        return;
    }
    char ch = str[0];
    str = str.substr(1);
    printReverse(str);
    cout<<ch;

}

string removeX(string str){
    if(str.length() == 0){
        return "";
    }
    char ch = str[0];
    str = str.substr(1);
    string ros = removeX(str);
    if(ch == 'x'){
        return ros + ch;
    }
    return ch + ros;
}

string removeDup(string str){
    // duplicates must be consecutive
    if(str.length() == 0){
        return "";
    }
    char ch = str[0];
    str = str.substr(1);
    string ros = removeDup(str);
    if(ch == ros[0]){
        return ros;
    }
    return ch + ros;
}

void replacePi(string str){
    if(str.length() == 0){
        return;
    }
    if(str[0] == 'p' && str[1] == 'i'){
        cout<<"3.14";
        replacePi(str.substr(2));
    }
    else{
        cout<<str[0];
        replacePi(str.substr(1));
    }
}

void toh(int n, char src, char dest, char helper){
    if(n == 0){
        return;
    }
    toh(n-1, src, helper, dest);
    cout<<"Moving "<<n<<" from "<<src<<" to "<<dest<<endl;
    toh(n-1, helper, dest, src);
}

int main()
{
    string str = "haarsshiit";
    // printReverse(str);
    // cout<<removeX(str);
    // cout<<removeDup(str);
    toh(3, 'A', 'B', 'C');
    return 0;
}