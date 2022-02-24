#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(vector<int> len, int breadth, int height){
    // question is exactly similar to finding the largest rectangle in the histogram

    vector<int> nsl;
    int size = len.size();
    stack<pair<int, int>> st;
    for (int i = 0; i < size; i++)
    {
        while(!st.empty() && st.top().first >= len[i]) st.pop();
        if(st.empty()) nsl.push_back(-1);
        else nsl.push_back(st.top().second);
        st.push({len[i], i});
    }

    // for(auto i : nsl) cout<<i<<" "; cout<<endl;

    vector<int> nsr;
    stack<pair<int, int>> st2;
    for (int i = size - 1; i >= 0; i--)
    {
        while (!st2.empty() && st2.top().first >= len[i]) st2.pop();
        if (st2.empty()) nsr.push_back(len.size());
        else nsr.push_back(st2.top().second);
        st2.push({len[i], i});
    }

    reverse(nsr.begin(), nsr.end());

    // for(auto i : nsr) cout<<i<<" "; cout<<endl;

    vector<int> dim; // dimensions of the largest gold block
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        int temp = nsr[i] - nsl[i] - 1;
        temp = temp * breadth * height * len[i];
        dim.push_back(temp);

        int vol = len[i] * breadth * height;
        total += vol;
    }

    // for(auto i : dim) cout<<i<<" "; cout<<endl;

    int maxVol = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if(dim[i] > maxVol) maxVol = dim[i];
    }

    // cout<<total<<" "<<maxVol<<endl;

    return (total - maxVol) % mod;



}

int main()
{
    int len; cin>>len;
    int breadth, height;
    cin>>breadth>>height;
    vector<int> v;
    for(int i = 0; i < len; i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }

    cout<<solve(v, breadth, height);
    return 0;
}