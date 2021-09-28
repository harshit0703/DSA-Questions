#include<iostream>
using namespace std;

// TC = O(2^n)

int count_maze_paths(int n, int rows, int cols){
 if (rows >= n || cols >= n){
     return 0;
 } else if (rows == n-1 && cols == n-1){
     return 1;
 }
 // at any given path we have two choices either to move down or right
    int count = 0;
    count += count_maze_paths(n, rows+1, cols); // left call for moving down
    count += count_maze_paths(n, rows, cols+1); // right call for moving right

    return count;

}

int main(){
    // we need to count the paths to reach the end of the 2d matrix there are no obstacles like in backtrack but we can only move down a row and to the next col ie down and right
    int n;
    cin>>n;
    int ans = count_maze_paths(n, 0, 0);  // it will be a square matrix
    cout<<ans;
    return 0;
}