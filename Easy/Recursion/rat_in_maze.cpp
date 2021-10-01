#include<iostream>
using namespace std;

bool is_safe(int** maze, int i, int j){
    if (maze[i][j] == 1){
        return true;
    }
    return false;
}

bool rat_in_maze(int **maze, int i, int j, int rows, int cols){
    if(i >= rows || j >= cols){
        return false;
    }

    if (i == rows-1 && j == cols-1){
        return true;
    }

    if (is_safe(maze, i+1, j)){
        rat_in_maze(maze, i+1, j, rows, cols);
        return true;
    }

    if (is_safe(maze, i, j+1)){
        rat_in_maze(maze, i, j+1, rows, cols);
        return true;
    }

    return false;

}

int main(){
    // we need to find the ways the rat can cross the maze with obstacles using backtracking
    int rows, cols;
    int maze[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>maze[i][j];
        }
    }

    int ans = rat_in_maze(maze);
    cout<<ans;

    return 0;
}