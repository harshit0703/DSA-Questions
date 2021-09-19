#include<iostream>
using namespace std;

int main(){
    //inverted half pyramind using repeated numbers
    int rows;
    cin>>rows;
    for(int i=0; i<rows; i++){
        for(int j=rows-i; j>=1; j--){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}