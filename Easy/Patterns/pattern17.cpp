#include <iostream>
using namespace std;

int main()
{
    //solid butterfly
    //butterfly = 2*(pair of opposite right triangles)
    int rows;
    cin>>rows;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=rows; j++){
            if(j<=i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        for (int j = rows; j >= 1; j--)
        {
            if (j > i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout<<endl;
    }

    for (int i = rows; i >= 1; i--)
    {
        for (int j = 1; j <= rows; j++)
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
        for (int j = rows; j >= 1; j--)
        {
            if (j > i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}