#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool>mp;

bool scrambledStr(string a, string b){

    if(a.compare(b) == 0){
        return true;
    }

    if(a.length() <= 0){
        return false;
    }

    string key = "";    // we need to create a unique key with both strings
    key.append(a);
    key.push_back(' '); 
    key.append(b);

    if(mp.find(key) != mp.end()){
        return mp[key];     // check if the value is already present
    }


    bool flag = false;

    for(int i = 1; i < a.length(); i++){

        // we simply breaked the problem into two conditions one for swapping and other for not swapping
        // swapping = compare the opposite parts of the strings
        // not swapping = compare the same parts of the strings
        // if either of them is true the ans is true otherwise false

        if((a.substr(0, i) == b.substr(i+1) && a.substr(i) == b.substr(0, a.length()-i)) || 
        (a.substr(0, i) == b.substr(0, i) && a.substr(i) == b.substr(i))){
            flag = true;
            break;
        }

    }

    return mp[key] = flag;  // keep storing the values inside the map to avoid overlapping

}

int main()
{
    string a, b;
    cin>>a>>b;
    if(a.length() != b.length()){
        return -1;
    }
    mp.clear();
    cout<<scrambledStr(a, b);

    return 0;
}