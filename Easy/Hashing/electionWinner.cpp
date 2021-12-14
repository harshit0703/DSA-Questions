#include<bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[], int n){
    unordered_map<string, int>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        int vote = 0;
        string name = "";
        
        for(auto i = mp.begin(); i != mp.end(); i++){
            int val = i->second;
            string key = i->first;
            
            if(val > vote){
                vote = val;
                name = key;
            }
            else if(val == vote){
                if(key < name){
                    name = key;
                }
            }
        }
        
        vector<string>ans;
        ans.push_back(name);
        ans.push_back(to_string(vote));
        return ans;

}

int main()
{
    string arr[] = {"harshit", "rishit", "sammy"};
    vector<string> ans = winner(arr, 3);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}