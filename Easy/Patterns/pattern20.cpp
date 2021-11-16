#include <iostream>
#include<algorithm>
using namespace std;

int main()
{   
    int n;
    cin>>n;

    for (int i = 0; i < 2*n-1 ; i++)
    {
        for (int j = 0; j < 2*n-1 ; j++)
        {
            int ans = n - min(i, min(j, min(n-i+1, n-j+1)));
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}