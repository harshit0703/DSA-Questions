#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f){

    if(e == 1){
        return f;   // we will start from the bottom and eventually our egg will only break on the critical floor
    }

    if(f == 0 || f == 1){
        return f;
    }

    int ans = INT_MAX;

    for(int k = 1; k <= f; k++){

        int eggBreaks = eggDrop(e-1, k-1);      // move downwards
        int eggRemains = eggDrop(e, f-k);       // move upwards

        int temp = 1 + max(eggBreaks, eggRemains);      // we need to conider for the worst case so we need max of these two

        ans = min(ans, temp);

    }

    return ans;

}

int main()
{
    int e, f;
    cin>>e>>f;
    int ans = eggDrop(e, f);
    cout<<ans;
    return 0;
}