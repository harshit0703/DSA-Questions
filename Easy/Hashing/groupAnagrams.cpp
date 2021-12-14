#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
    
    unordered_map<string, vector<string>>mp;

    for(auto i : strs){
        string temp = i;
        sort(temp.begin(), temp.end()); // since all anagrams will be same after sorting we can use it as a key to store all anagrams
        mp[temp].push_back(i);
    }

    vector<vector<string>>ans;

    for(auto i : mp){
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    vector<string>strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>>ans = groupAnagrams(strs);
    for(int i = 0; i< ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;       
    }
    return 0;
}