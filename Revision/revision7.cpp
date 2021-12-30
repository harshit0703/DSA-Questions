#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}};

bool isValid(int row, int col){
    // queen it kills in all vertical horizontal as well as diagonally
    // same column
    int i = row;
    int j = col;
    while(i >= 0){
        if(arr[i][col] == 1){
            return false;
        }
        i--;
    }
    // same primary diagonal
    i = row;
    while(i >= 0 && j >= 0){
        if(arr[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    // same secondary diagonal
    i = row;
    j = col;
    while(i >= 0 && j < arr.size()){
        if(arr[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    
    return true;
}

bool nQueen(int row){
    if(row >= arr.size()){
        return true;
    }
    for(int col = 0; col < arr.size(); col++){
        if(isValid(row, col)){
            arr[row][col] = 1;
        }
        if(nQueen(row + 1)){
            return true;
        }
        // backtracking step
        arr[row][col] = 0;
    }
    return false;
}

void print(){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    nQueen(0);
    print();

    return 0;
}