#include<bits/stdc++.h>
using namespace std;

// defining some pairs to be used in heaps
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;
// **************************************

int kthLargest(vector<int> v, int k){
    if(k > v.size()) return -1;
    // since we know the top of the max heap always point to the largest element 

    priority_queue<int> q;
    for(auto i : v) q.push(i); // we filled the whole heap so there would be no effect in TC it will remain O(nlogn)
    while(k > 1){
        q.pop();
        k--;
    }
    return q.top();
}

int kthLargestOpt(vector<int> v, int k){
    // make a min heap and dont let its size get greater than k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i : v){
        minHeap.push(i);
        if(minHeap.size() > k) minHeap.pop();
        // since we are not letting the size of the heap getting bigger than k TC = O(nlogk)
    }
    return minHeap.top();
}

int kthSmallest(vector<int> v, int k){
    if(k > v.size()) return -1;
    // since we know that the top of the min heap will always point to the smallest element

    priority_queue<int, vector<int>, greater<int>> q;
    for(auto i : v) q.push(i);
    while(k > 1){
        q.pop();
        k--;
    }
    return q.top();
}

vector<int> kLargestElements(vector<int> v, int k){
    if(k > v.size()) return {};
    vector<int> ans;
    priority_queue<int> q;
    for(auto i : v) q.push(i);
    while(k >= 1){
        ans.push_back(q.top());
        q.pop();
        k--;
    }

    return ans;
}

vector<int> sortKsorted(vector<int> v, int k){
    // TC = O(nlogk)
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i : v){
        q.push(i);
        if(q.size() > k){
            ans.push_back(q.top());
            q.pop();
        }
    }

    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }

    return ans;
}

vector<int> kClosestNums(vector<int> v, int k, int x){
    vector<int> ans;
    priority_queue<pi> q;
    for(int i = 0; i < v.size(); i++){
        int diff = abs(x - v[i]);
        q.push({diff, v[i]});
        if(q.size() > k) q.pop();
    }

    while(!q.empty()){
        ans.push_back(q.top().second);
        q.pop();
        // k--;
    }

    return ans;

}

vector<int> topkFrequent(vector<int> v, int k){
    // since we are dealing with the frequency we have to consider the map :D

    unordered_map<int, int>mp;
    for(auto i : v)mp[i]++;
    priority_queue<pi, vector<pi>, greater<pi>> q;

    for(auto i : mp){
        q.push({i.second, i.first});    // we want to sort accoring to the frequency
        if(q.size() > k) q.pop();
    }

    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.top().second);
        q.pop();
    }

    return ans;
}

double calcDistance(vector<int> v)
{
    double dis = pow(v[0], 2) + pow(v[1], 2);
    return sqrt(dis);
}

vector<vector<int>> kClosestOrigin(vector<vector<int>> &points, int k)
{

    priority_queue<pair<double, vector<int>>> q;
    vector<vector<int>> ans;

    for (int i = 0; i < points.size(); i++)
    {
        double distance = calcDistance(points[i]);
        q.push({distance, points[i]});
        if (q.size() > k)
            q.pop();
    }

    while (!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }

    return ans;
}

int connectRopes(vector<int> v){
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto i : v) q.push(i);
    int cost = 0;
    while(q.size() > 1){
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        int connecting_cost = first + second;
        cost += connecting_cost;
        q.push(connecting_cost);
    }

    return cost;
}

void test(){
    pair<int, int> p = {1, 4};
    pair<int, int> q = {3, 5};
    pair<int, int> r = {3, 5};
    priority_queue<pair<int, int>> h;
    h.push(p);
    h.push(q);
    h.push(r);
    cout<<h.top().first<<"->"<<h.top().second;
    // it will compare with the first value of the pair if it comes to be the same then the one which comes after will be on the top
}

int main()
{
    // we have two types of heaps min heap and max heap
    // as the name suggests min heap will have the min element at its top where as max heap it will have a max element at the top

    vector<int> v = {3, 4, 19, 1, 5, 7};
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 

    for(auto i : v){
        maxHeap.push(i);
        minHeap.push(i);
    }

    // cout<<maxHeap.top()<<" "<<minHeap.top();

    cout<<kthLargest(v, 3)<<endl;
    cout<<kthSmallest(v, 2)<<endl;

    vector<int> ans = kLargestElements(v, 3);
    for(int i : ans)cout<<i<<" ";
    cout<<endl;
    cout<<kthLargestOpt(v, 3)<<endl;
    test();
    cout<<endl;
    vector<int> ksorted = {6, 5, 3, 2, 8, 10, 9};
    vector<int> res = sortKsorted(ksorted, 3);
    for(int i : res){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> closestk = {10, 2, 14, 4, 7, 6};
    vector<int> resK = kClosestNums(closestk, 3, 5);
    for(auto i : resK){
        cout<<i<<" ";
    }

    cout<<endl;

    vector<int> kfreq = {1, 1, 1, 3, 2, 2, 4};
    vector<int> Kfreq = topkFrequent(kfreq, 2);
    for(auto i : Kfreq){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<connectRopes({1, 2, 3, 4, 5});

    return 0;
}