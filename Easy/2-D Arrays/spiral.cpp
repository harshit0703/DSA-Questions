#include<iostream>
using namespace std;

int main(){
    //in spiral order we traverse from first row then to last col then last row and finally first col
    int rows,cols;
    cin>>rows>>cols;
    int mat[rows][cols];
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>mat[i][j];
        }
    }

    int row_start = 0, row_end = rows-1, col_start = 0, col_end = cols-1;

    while(row_start<=row_end && col_start<=col_end){
        // first row
        for(int i=col_start; i<=col_end; i++){
            cout<<mat[row_start][i]<<endl;
        }
        row_start++;

        // last col
        for(int i=row_start; i<=row_end; i++){
            cout<<mat[i][col_end]<<endl;
        }
        col_end--;

        // last row
        for(int i=col_end; i>=col_start; i--){
            cout<<mat[row_end][i]<<endl;
        }
        row_end--;

        // first col
        for(int i=row_end; i>=row_start; i--){
            cout<<mat[i]<<col_start<<endl;
        }
        col_start++;
    }

    return 0;
}