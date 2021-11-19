#include<bits/stdc++.h>
using namespace std;

int minWinSubStr(string str, string p){
    int ans = INT_MAX;
    unordered_map<char, int> mp;
    
    for(auto i : p){
        mp[i]++;
    }
    
    int i = 0;
    int j = 0;

    while(j < str.length()){
        
        if(mp.find(str[j]) != mp.end()){
            mp[str[j]]--;
            if(mp[str[j]] == 0){
                if(mp.size() == p.length()){
                    i = j;      // marks the start of the possible window
                }
                mp.erase(str[j]);
            }
            if(mp.size() == 0){
                ans = min(ans, j - i + 1);
                if(j < str.length()){
                    for(auto k : p){
                        mp[k]++;
                    }
                    i = j;
                }
            }
        }
        j++;
    }

    return ans;
}

int main()
{
    string str = "adobecodebanc";
    string p = "abc";
    int ans = minWinSubStr(str, p);
    cout<<ans;
    return 0;
}