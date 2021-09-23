#include<iostream>
using namespace std;

int main(){
    // simple searching in a 2D matrix
    // TC = O(n^2)
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
    int flag = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if (key == mat[i][j]){
                cout<<i<<" "<<j;
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0){
        cout<<"element not found.";
    }

    return 0;
}