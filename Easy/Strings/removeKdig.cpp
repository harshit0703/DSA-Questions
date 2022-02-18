#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string str, int k){
    vector<int> num;
    for(auto i : str){
        num.push_back(i - '0');
    }

    vector<int> sml, smr;
    sml.push_back(num[0]);
    smr.push_back(num[num.size() - 1]);
    for(int i = 1; i < str.length(); i++){
        if(num[i] < sml[i-1]) sml[i] = num[i];
        else sml[i] = sml[i-1];
    }

    for(int i = str.length() - 2; i >= 0; i++){
        if(num[i] < smr[i+1]) smr[i] = num[i];
        else smr[i] = smr[i+1];
    }

    int temp = 0;

    for(auto i = num.begin(); i != num.end(); i++){
        if(*i != sml[temp] || *i != smr[temp]){
            num.erase(i);
            k--;
        }
        temp++;
    }

    int ans = num.size() - k;
    

}

int main()
{
    
    return 0;
}