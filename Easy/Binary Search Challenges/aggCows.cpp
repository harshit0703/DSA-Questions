#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &stalls, int dist, int k){

    int count = 1;
    int lastPos = stalls[0];

    for(int i = 0; i < stalls.size(); i++){
        if(stalls[i] - lastPos >= dist){
            count++;
            lastPos = stalls[i];
        }
    }

    if(count == k){
        return true;
    }

    return false;

}

int aggressiveCows(vector<int>stalls, int k){

    sort(stalls.begin(), stalls.end());

    int st = 0;
    int en = stalls[stalls.size() - 1];

    int res = -1;

    while(st <= en){

        int mid = st + (en - st)/2;     // maximum possible distance
        if(isValid(stalls, mid, k)){
            res = mid;
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }

    }

    return res;

}

int main()
{
    vector<int>stalls = {4, 2, 1, 3, 6};
    int ans = aggressiveCows(stalls, 2);
    cout<<ans;
    return 0;
}