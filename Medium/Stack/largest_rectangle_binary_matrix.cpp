#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int MAH(vector<int> v){
    
    vector<int> left; // for NSL indexes
    vector<int> right;  // for NSR indexes
    vector<int> width; // of the rectangles that can be formed

    stack<pair<int,int>> st;
    int temp_left_idx = -1;
    for(int i=0; i<v.size(); i++){
        if(st.empty()){
            left.push_back(temp_left_idx);
        }
        else{
            while(!st.empty() && st.top().first >= v[i]){
                st.pop();
            }
            if(st.empty()){
                left.push_back(temp_left_idx);
            }else{
                left.push_back(st.top().second);
            }
        }
        st.push({v[i], i});
    }
    // after this branch of code we will get the left vector with indexes of NSL

    stack<pair<int,int>>st2;
    int temp_right_idx = v.size();
    for(int i=v.size()-1; i>=0; i--){
        if(st2.empty()){
            right.push_back(temp_right_idx);
        }
        else{
            while(!st2.empty() && st2.top().first >= v[i]){
                st2.pop();
            }
            if(st2.empty()){
                right.push_back(temp_right_idx);
            }else{
                right.push_back(st2.top().second);
            }
        }
        st2.push({v[i], i});
    }
    reverse(right.begin(), right.end());  // since we are moving from right to left we need to reverse the vector
 

    for(int i=0; i<v.size(); i++){
        int n = right[i] - left[i] - 1;
        width.push_back(n);
    }


    int max_area = INT_MIN;
    for(int i=0; i<v.size(); i++){
        int area = width[i] * v[i];
        max_area = max(area, max_area);
    }

    return max_area;
}

int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // similar to largest area histogram now we are given with a 2-d binary matrix and we need to find the max area this problem is nothing but a variation to MAH as now we can break the matrix into 1-d arrays and make sepearte histograms for each of them and finally return the max

    vector<int> ans;
    for(int j=0; j<n; j++){
        ans.push_back(arr[0][j]);  // the first rown wil be copied as it is
    }

    int max_area = MAH(ans);
    
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0){
                ans[j] = 0;
            }else{
                ans[j] += arr[i][j];
            }
        }
        max_area = max(max_area, MAH(ans));  // this will find the maximum possible area for the 2-d matrix
    }

    cout<<max_area;
    
    return 0;
}