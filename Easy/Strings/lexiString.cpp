#include<bits/stdc++.h>
using namespace std;

string lexiStr(string reorder, string str){
    
    if(str.length() == 0) return "";

    unordered_map<char, int> mp;
    for(int i = 0; i < reorder.length(); i++){
        mp[reorder[i]] = i;
    }

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> minHeap;

    for(auto i : str){
        pair<int, char> p;
        p.first = mp[i];
        p.second = i;
        minHeap.push(p);
    }

    string ans = "";

    while(!minHeap.empty()){
        auto i = minHeap.top();
        minHeap.pop();
        ans += i.second;
    }

    return ans;

}

int main()
{
    string reorder = "qwryupcsfoghjkldezvxbintma";
    string str = "ativedoc";
    string ans = lexiStr(reorder, str);
    cout<<ans;
    return 0;
}