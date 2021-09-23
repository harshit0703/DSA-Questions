#include<iostream>
using namespace std;

int main(){
    //for tow matrices to be multiplied together the cols of the first need to be equal to the rows of the second
    int a,b;
    cin>>a>>b;
    int mat1[a][b];
    
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cin>>mat1[i][j];
        }
    }

    int c,d;
    cin>>c>>d;
    int mat2[c][d];
    for(int i=0; i<c; i++){
        for(int j=0; j<d; j++){
            cin>>mat2[c][d];
        }
    }

    if(b!=c){
        cout<<"Matrices cannot be multiplied.";
        return 0;
    }

    int ans[a][d];
    for(int i=0; i<a; i++){
        for(int j=0; j<d; j++){
            for(int k=0; k<b; k++){
                ans[i][j] += mat1[i][k] * mat2[k][j]; 
            }
        }
    }

    for(int i=0; i<a; i++){
        for(int j=0; j<d; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}