#include<iostream>
using namespace std;

int main(){
    //diamond pattern
    int rows;
    cin>>rows;
    // diamond = upside triangle + downside triangle
    for(int i=1; i<=rows; i++){
        for(int j=rows; j>=1; j--){
            if(j<=i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for(int k=2; k<=i; k++){
            cout<<"*";
        }
        cout<<endl;
    }

    for (int i = rows; i >= 1; i--)
    {
        for (int j = rows; j >= 1; j--)
        {
            if (j <= i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        for (int k = 2; k <= i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}