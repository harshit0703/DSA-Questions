#include<iostream>
using namespace std;

int main(){
    //hollow rectangle
    
    int rows,columns;
    cin>>rows>>columns;

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            //we need to print complete first and last columns and only first and last row
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)
            {
                cout << "*";
            }
           else{
               cout<<" ";
           }
        }
        cout<<endl;
    }

    return 0;
}