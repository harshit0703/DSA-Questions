#include<iostream>
using namespace std;

// TC = O(2^n)

bool is_safe(int** board, int i, int j, int n){
    // a queen can cut in both vertically and diagonally
    // since only one queen will be placed in each row we dont need to check horizontally
    int rows = i;
    int cols = j;
    while(rows>=0 && cols>=0){
        if (board[rows][cols] == 1){
            return false;
        }
        rows--;
        cols--;
    }
    
    for (int rows = 0; rows<i; rows++){
        if(board[rows][j] == 1){
            return false;
        }
    }

    rows = i;
    cols = j;
    while(rows>=0 && cols<n){
        if (board[rows][cols] == 1){
            return false;
        }
        rows--;
        cols++;
    }

    return true;

}

bool nqueen(int** board, int i, int n){

    if (i >= n){
        return true;
    }

    for (int j=0; j<n; j++){
        if (is_safe(board, i, j, n)){
            board[i][j] = 1;

        if(nqueen(board, i+1, n)){
            return true;
        }

        board[i][j] = 0;  // backtracking

        }
    }

    return false;

}

int main(){
    // we have to place n queens in nxn board such that no queen can cut any other queen
    int n;
    cin>>n;
    int** board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    
    if(nqueen(board, 0, n)){
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    
    return 0;
}