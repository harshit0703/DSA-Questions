#include<bits/stdc++.h>
using namespace std;

int kSmallest(vector<int>arr, int k){
    priority_queue<int>maxH;        // since we have to find the smallest we will make a max heap
    for (int i = 0; i < arr.size(); i++)
    {
        maxH.push(arr[i]);
        if(maxH.size() > k){
            maxH.pop();             // in this way the size of the heap never exeeds k and hence the TC = O(nlogk)
        }
    }
    return maxH.top();
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int ans = kSmallest(arr, 3);
    cout<<ans;
    return 0;
}