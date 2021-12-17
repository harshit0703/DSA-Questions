#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>&arr, int i, int j, int ans){
    
    // checking for row
    for(int col = 0; col < arr.size(); col++){
        if(arr[i][col] == ans){
            return false;
        }
    }

    // checking for col
    for(int row = 0; row < arr.size(); row++){
        if(arr[row][j] == ans){
            return false;
        }
    }

    // checking for sub-matrix
    int smi = (i/3) * 3;
    int smj = (j/3) * 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[smi + i][smj + j] == ans){
                return false;
            }
        }
    }

    return true;

}

void solveSudoku(vector<vector<int>>&grid, int i, int j){

if(i == grid.size()){
    return ;
}

int ni = 0;
int nj = 0;

if(j == grid.size() - 1){
    ni = i+1;
    nj = 0;  
}else{
    ni = i;
    nj = j+1;
}

if(grid[i][j] != 0){
    solveSudoku(grid, ni, nj);
}else{
    for(int pa = 0; pa <=9; pa++){
        if(isValid(grid, i, j, pa)){
            grid[i][j] = pa;
            solveSudoku(grid, ni, nj);
            grid[i][j] = 0;
        }
    }
}

}

    int main()
{

    vector<vector<int>>sudoku = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0,},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0} };


    solveSudoku(sudoku, 0, 0);

    for(int i = 0; i < sudoku.size(); i++){
        for(int j = 0; j < sudoku[i].size(); j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}