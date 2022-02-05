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

vector<int> maxOfAllSubarraysizeK(vector<int> v, int k){
    list<int> l;
    vector<int> ans;
    int i = 0;
    int j = 0;

    while(j < v.size()){
        while(v[j] > l.back() && !l.empty()){
            l.pop_back();
        }
        l.push_back(v[j]);

        if(j - i + 1 == k){
            ans.push_back(l.front());
            if(l.front() == v[i]){
                l.pop_front();
            }
            i++;
        }

        j++;
    }

    return ans;

}

int largestSubarrayofSumK(vector<int> v, int k){
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = INT_MIN;

    while(j < v.size()){
        sum += v[j];

        if(sum == k){
            ans = max(ans, j - i + 1);
        }
        else if(sum > k){
            while(sum > k){
                sum -= v[i];
                i++;
            }
        }
        j++;
        }

        return ans;
}

int longlestSubstrKunique(string str, int k){
        if(k > str.length()){
            return -1;
        }
        int i = 0;
        int j = 0;
        int uniqueChar = 0;
        int ans = INT_MIN;
        unordered_map<char, int> mp;

        while(j < str.length()){
            mp[str[j]]++;
            if(mp[str[j]] == 1) uniqueChar++;

            if(uniqueChar == k){
                ans = max(ans, j-i+1);
            }

            if(uniqueChar > k){
                while(uniqueChar > k){
                    mp[str[i]]--;
                    if(mp[str[i]] == 0) uniqueChar--;
                    i++;
                }
            }

            j++;

        }

        return ans;
}

int largestSubstrwithoutRepeatingChar(string str){
    int i = 0;
    int j = 0;
    int ans = 0;
    unordered_map<char, int>mp;

    while(j < str.length()){
        mp[str[j]]++;
        if(mp[str[j]] > 1){
            while(mp[str[j]] > 1){
                mp[str[i]]--;
                if(mp[str[i]] == 0){
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        int size = mp.size();
        ans = max(ans, size);
        j++;
    }

    return ans;
}

int pickToys(string str){
    // condition mentioned the unique toys must not be more than 2

    int i = 0;
    int j = 0;
    int size = 0;
    int ans = 0;
    unordered_map<char, int> mp;

    while(j < str.length()){
        mp[str[j]]++;
        size++;
        
        if(mp.size() == 2){
            ans = max(size, ans);
        }

        else if (mp.size() > 2){
            while(mp.size() > 2){
                mp[str[i]]--;
                size--;
                if(mp[str[i]] == 0){
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        j++;
    }

    return ans;

}

int main()
{
    cout<<cntAnagrams("abc", "abaacbabc")<<endl;
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxOfAllSubarraysizeK(v, 3);
    // for(auto i : ans){
    //     cout<<i<<" ";
    // }

    // cout<<largestSubarrayofSumK({4, 1, 1, 1, 2, 3, 5}, 5);
    // cout<<longlestSubstrKunique("aabacbebebe", 3);
    // cout<<largestSubstrwithoutRepeatingChar("abcabcbb");
    // cout<<pickToys("abaccab");

    return 0;
}