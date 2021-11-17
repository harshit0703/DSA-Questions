#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findFirstNegative(int arr[], int n, int k){
    queue<int> q;
    vector<int> ans;

    int i = 0;
    int j = 0;
    
    while(j < n){
        if(arr[j] < 0){
            q.push(arr[j]);
        }
        if(j - i + 1 < k){
            j++;
        }
        else if(j - i + 1 == k){
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.front());
            if(q.front() == arr[i]){
                q.pop();
            }
            }           
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> ans = findFirstNegative(arr, 8, k);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}