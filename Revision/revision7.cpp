#include<bits/stdc++.h>
using namespace std;

bool isValid(int** arr, int row, int col, int n){
    int i = row;
    int j = col;
    // same column
    while(i >= 0){
        if(arr[i][col] == 1){
            return false;
        }
        i--;
    }
    // primary diagonal
    i = row;
    while(i >= 0 && j >= 0){
        if(arr[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    // secondary diagonal
    i = row;
    j = col;
    while(i >= 0 && j < n){
        if(arr[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool nQueen(int** arr, int row, int n){
    if(row >= n){
        return true;
    }
    for(int col = 0; col < n; col++){
        if(isValid(arr, row, col, n)){
            arr[row][col] = 1;
            if (nQueen(arr, row + 1, n))
            {
                return true;
            }
            arr[row][col] = 0; // backtracking
        }
    }
    return false;
}

bool isSafe(int** arr, int row, int col, int n){
    if(row >= n || col >= n || arr[row][col] == 0){
        return false;
    }
    return true;
}

bool ratInMaze(int** arr, int row, int col, int n){

    if(row == n-1 && col == n-1){
        return true;
    }

   if(isSafe(arr, row, col, n)){
       int temp = arr[row][col];
       arr[row][col] = 2;
       if(ratInMaze(arr, row + 1, col, n)){
           return true;
       }
       if(ratInMaze(arr, row, col + 1, n)){
           return true;
       }
       arr[row][col] = temp;
   }

   return false;

}

int main()
{
    /* int n;
    cin>>n;
    int** arr = new int*[n]; // double pointer for a 2d array
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

    if(nQueen(arr, 0, n)){
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    } */

    int n;
    cin>>n;
    int** arr = new int*[n]; // double pointer for a 2d array
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    if(ratInMaze(arr, 0, 0, n)){
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}