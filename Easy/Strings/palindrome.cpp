#include<iostream>
using namespace std;

int main(){
    char arr[8];
    cin>>arr;
    int start = 0, end = 6;
    while(start <= end){
        if(arr[start] == arr[end]){
            start++;
            end--;
        }else{
            break;
        }
    }
    if(start > end){
        cout<<"It is a palindrome.";
    }else{
        cout<<"Not a palindrome.";
    }
    return 0;
}