#include<iostream>
using namespace std;

int nextLetter(char arr[], int n, char key){
    int st = 0;
    int en = n-1;
    int res = -1;
    while(st <= en){
        int mid = st + (en - st)/2;
        if(arr[mid] > key){         // characters can be compared like this
            res = mid;
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return res;
}

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'f', 'h'};
    int ans = nextLetter(arr, 6, 'f');
    if(ans == -1){
        cout<<"Next character is not found.";
    }else{
        cout<<arr[ans];
    }
    return 0;
}