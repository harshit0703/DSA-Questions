#include<bits/stdc++.h>
using namespace std;

void solve(string str){
    string alpha = "";
    string nums = "";

    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            nums += str[i];
        }else{
            alpha += str[i];
        }
    }

    if(alpha.length() == 0 || nums.length() == 0){
        cout<<-1;
        return;
    }

    sort(alpha.begin(), alpha.end());
    sort(nums.begin(), nums.end());

    int first_alpha, last_alpha;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == alpha[0]){
            first_alpha = i;
            break;
        }
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] == alpha[alpha.length() - 1]){
            last_alpha = i;
            break;
        }
    }

    int alpha_diff = abs(last_alpha - first_alpha);

    int first_num, last_num;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == nums[0]){
            first_num = i;
            break;
        }
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] == nums[nums.length() - 1]){
            last_num = i;
            break;
        }
    }

    int num_diff = abs(last_num - first_num);
    int sum = 0;
    for(int i = 0; i < nums.length(); i++){
        int n = nums[i] - '0';
        sum += n;
    }

    cout<<alpha<<alpha_diff<<":"<<sum<<num_diff;

}

void solve2(vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> common;
    int prev = -1;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] != prev && a[i] == b[j]){
                common.push_back(a[i]);
            }
        }
    }

    if(common.size() == 0){
        cout<<-1;
        return;
    }

    sort(common.begin(), common.end());
    int m = common[0];

    while(m > 9){
        int dig = m % 10;
        m /= 10;
        m = m + dig;
    }

    if(m == 0 || m > a.size() || m > b.size()){
        cout<<-1;
        return;
    }

    vector<int>a_largest;
    vector<int>b_largest;

    for(int i = 0; i < m; i++){
        a_largest.push_back(a[a.size() - i + 1]);
        b_largest.push_back(b[b.size() - i + 1]);
    }

    sort(a_largest.begin(), a_largest.end());
    sort(b_largest.begin(), b_largest.end());

    vector<vector<int>> ans;
    ans[0] = a_largest;
    ans[1] = b_largest;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

}

int main()
{
    solve("gt4r22w7e");
    return 0;
}