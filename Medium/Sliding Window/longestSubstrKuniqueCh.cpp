#include<bits/stdc++.h>
using namespace std;

int solve(string str, int k){
    int ans = -1;

    int i = 0;
    int j = 0;
    unordered_map<char, int> mp;

    while(j < str.length()){
        mp[str[j]]++;

        if(mp.size() < k){
            j++;
        }
        else if(mp.size() == k){
            ans = max(ans, j - i + 1);
            j++;
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[str[i]]--;
                if(mp[str[i]] == 0){
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main()
{
    string str = "aabacbebebe";
    int ans = solve(str, 3);
    cout<<ans;
    return 0;
}