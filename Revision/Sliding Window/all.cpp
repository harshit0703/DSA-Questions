#include<bits/stdc++.h>
using namespace std;

int cntAnagrams(string pat, string str){
    // first create a map for the given pattern
    unordered_map<char, int> mp;
    for(auto i : pat) mp[i]++;
    int cnt = mp.size();    // number of distinct elements
    int i = 0;
    int j = 0;
    int ans = 0;

    while(j < str.length()){

        if(mp.find(str[j]) != mp.end()){
            mp[str[j]]--;
            if(mp[str[j]] == 0) cnt--;
        }

        if(j - i + 1 == pat.length()){
            if(cnt == 0){
                ans++;
            }
            if(mp.find(str[i]) != mp.end()){
                mp[str[i]]++;
                if(mp[str[i]] == 1) cnt++;
            }
            i++;
        }

        j++;

    }

    return ans;
}

int main()
{
    cout<<cntAnagrams("aaba", "aabaabaa");
    return 0;
}