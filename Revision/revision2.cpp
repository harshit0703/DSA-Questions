#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

bool simpleSearch(int key){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            if(arr[i][j] == key){
                cout<<"Element present at index :"<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool effecientSearch(int key){
    // since the matrix is sorted by both rowwise and columnwise we can reduce the time complexity from O(n) to O(logn) 
    // start from either top right or lower left corner as by doing so at each iteration you can neglect a row or col

    int i = 0;
    int j = arr.size() - 1;

    while(j > 0 && i < arr.size()){
        if(key == arr[i][j]){
            cout<<"Element present at index :"<<i<<" "<<j<<endl;
            return true;
        }
        else if(key > arr[i][j]){
            i++;
        }
        else{
            j--;
        }
    }

    return false;

}

void transpose(){
    // transpose of a matrix is noting but interchanging the rows with columns
    // we can achieve this simply by swapping elements across the diagonal
    vector<vector<int>>v = arr;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // traversing the upper triangle
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v[i].size(); j++){
            if(i != j){
                int temp = v[i][j];
                v[i][j] = v[j][i];
                v[j][i] = temp;
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void spiralOrder(){
    int frow = 0, lrow = arr.size() - 1;
    int fcol = 0, lcol = arr.size() - 1;

    while(frow <= lrow && fcol <= lcol){

        // top row
        for(int i = fcol; i <= lcol; i++){
            cout<<arr[frow][i]<<" ";
        }
        frow++;

         // last column
        for(int i = frow; i <= lrow; i++){
            cout<<arr[i][lcol]<<" ";
        }
        lcol--;

         // bottom row
        for(int i = lcol; i >= fcol; i--){
            cout<<arr[lrow][i]<<" ";
        }
        lrow--;

         // first column
        for(int i = lrow; i >= frow; i--){
            cout<<arr[i][fcol]<<" ";
        }
        fcol++;

    }
}

int main()
{
    // cout<<simpleSearch(13)<<endl;
    // cout<<effecientSearch(13)<<endl;
    // transpose();
    spiralOrder();
    return 0;
}