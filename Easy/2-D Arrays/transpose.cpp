#include<iostream>
using namespace std;

int main(){
    //we need to print the transpose of a matrix 
    // the idea is to swap only the upper triangle elements with the lower triangle elements or elements across the main diagonal
    // TC = O(n^2)
    int rows,cols;
    cin>>rows>>cols;
    int mat[rows][cols];
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>mat[i][j];
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=i+1; j<cols; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}