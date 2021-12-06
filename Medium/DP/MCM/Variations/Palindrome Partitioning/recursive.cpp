#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string str, int i, int j){

    while(i <= j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;

}

int mcm(string str, int i, int j){
    
    if(i >= j){
        return 0;   // base condition
    }

    if(ispalindrome(str, i, j)){
        return 0;
    }

    int ans = INT_MAX;

    for(int k = i; k <= j-1; k++){
        int temp1 = mcm(str, i, k);
        int temp2 = mcm(str, k+1, j);
        int tempAns = temp1 + temp2 + 1;
        ans = min(ans , tempAns);
    }

    return ans;

}

int main()
{
    string str = "niti";
    int ans = mcm(str, 1, 4); 
    cout<<ans;
    return 0;
}