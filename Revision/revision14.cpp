#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> board, int row, int col){
    // same column
    int j = col;
    int i = row;
    for(; i >= 0; i--){
        if(board[i][j] == 1){
            return false;
        }
    }
    // same primary diagonal
    i = row;
    while(i >=0 && j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    // same secondary diagonal
    i = row;
    j = col;
    while(i >= 0 && j < board.size()){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }

    // valid position
    return true;
}

bool nQueens(vector<vector<int>> &board, int row){

    if(row >= board.size()){
        return true;
    }

    // since a queen cuts in all possible directions i.e vertically, horizontally and diagonally we can place only 1 queen in each row

    for(int i = 0; i < board.size(); i++){
        
        if(isValid(board, row, i)){
            board[row][i] = 1;
        

        if(nQueens(board, row + 1)){
            return true;
        }

        // we will only reach this statement if the given position is not valid and  then we will back track by changing our ans to its initial value
        board[row][i] = 0; // backtracking
        }
    }

    return false;

}

int main()
{   int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int> (n, 0));
    // this will initialize the n*n vector with 0
    nQueens(board, 0);
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}