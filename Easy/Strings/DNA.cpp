#include<bits/stdc++.h>
using namespace std;

void dna(){
    int n; cin>>n;
    string str; cin>>str;
    int folds = 0;
    int ans = INT_MIN;
    string cmp = "";

    while(str.length() != 0){
        string first = str.substr(0,1);
        str = str.substr(1);
        cmp = first + cmp;

        int bonds = 0;

        for(int i = 0; i < cmp.length(); i++){
            if(cmp[i] == 'A' && str[i] == 'T'){
                bonds++;
            }else if(cmp[i] == 'T' && str[i] == 'A'){
                bonds++;
            }else if(cmp[i] == 'C' && str[i] == 'G'){
                bonds++;
            }else if(cmp[i] == 'G' && str[i] == 'C'){
                bonds++;
            }
        }

        if(bonds > ans){
            ans = bonds;
            folds = cmp.length();
        }
    }

    cout<<folds<<" "<<ans;
}

int main()
{   
    dna();
    return 0;
}