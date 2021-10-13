#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rainwater(vector<int> v){

    int left[v.size()];
    left[0] = v[0];     // this array will contain the absolute max on left

    for(int i=1; i<v.size(); i++){
        left[i] = max(left[i-1], v[i]);
    }

    int right[v.size()];
    right[0] = v[v.size() - 1];   // this array will contain the absolute max on right

    for(int i=v.size()-2; i>=0; i--){
        right[i] = max(v[i], right[i+1]);
    }

    int water_trapped = 0;

    for(int i=0; i<v.size(); i++){
        water_trapped += min(right[i], left[i]) - v[i]; // this will give the height of the water stored
    }

    return water_trapped;
}

int main(){
    vector<int> v;
    int size;
    cin>>size;
    for(int i=0; i<size; i++){
        int n;
        cin>>n;
        v.push_back(n);
    }

    int ans = rainwater(v);
    cout<<ans;

    return 0;
}