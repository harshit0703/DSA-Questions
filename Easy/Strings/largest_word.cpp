#include<iostream>
using namespace std;

int main(){
    char arr[100];
    cin.getline(arr, 100);
    int i = 0;
    int max_len = 0, curr_len = 0;
    while(arr[i] != '\0'){
        if(arr[i] != " "){
            curr_len++;
        }else{
            max_len = max(max_len, curr_len);
            curr_len = 0;
        }
        i++;
    }
    return 0;
}