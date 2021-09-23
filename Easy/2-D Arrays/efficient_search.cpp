#include<iostream>
using namespace std;

int main(){
    // now we are searching for a key in a sorted 2d array
    // TC = O(rows+cols)
    int rows,cols;
    cin>>rows>>cols;
    int mat[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>mat[i][j];
        }
    }

    int key;
    cin>>key;

    int i=0, j=cols-1;

    while(i<rows && j>0){
        if (key == mat[i][j]){
            cout<<"Element found at index:"<<i<<" "<<j;
            break;
        }else if(key>mat[i][j]){
            i++;
        }else{
            j--;
        }
    }

    if(i==rows || j==0){
        cout<<"Element not found.";
    }

    return 0;
}