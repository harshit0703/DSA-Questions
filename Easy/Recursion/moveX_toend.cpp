#include<iostream>
#include<string>
using namespace std;

void shift_x(string str, string not_x, string x){
    if(str.size() == 0){
        cout<<not_x + x;
        return;
    }
    if (str[0] == 'x'){
        shift_x(str.substr(1), not_x, x + str[0]);
    }else{
        shift_x(str.substr(1), not_x + str[0], x);
    }
}

int main(){
    string str;
    cin>>str;
    shift_x(str,"","");
    return 0;
}