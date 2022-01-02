#include<bits/stdc++.h>
using namespace std;

void printSubsets(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    str = str.substr(1);
    printSubsets(str, ans);
    printSubsets(str, ans + ch);
}

bool check(vector<string>&unique, string ans){
    for(int i = 0; i < unique.size(); i++){
        if(unique[i] == ans){
            return true;
        }
    }
    return false;
}

void printUniqueSubsets(string str, string ans, vector<string>&unique){
    if(str.length() == 0){
        if(!check(unique, ans)){
            unique.push_back(ans);
        }
        return;
    }
    char ch = str[0];
    str = str.substr(1);

    printUniqueSubsets(str, ans, unique);
    printUniqueSubsets(str, ans + ch, unique);
}

void permutationSpaces(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    str = str.substr(1);
    if(str.length() != 0){
        permutationSpaces(str, ans + ch);
        permutationSpaces(str, ans + ch + '-');
    }
    else{
        permutationSpaces(str, ans + ch);
    }
    
}

void permutationCase(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char lower = str[0];
    char upper = toupper(lower);
    str = str.substr(1);
    permutationCase(str, ans + lower);
    permutationCase(str, ans + upper);
}

void permutationLetterCase(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    str = str.substr(1);
    if(isalpha(ch)){
        char lower = tolower(ch);
        char upper = toupper(ch);
        permutationLetterCase(str, ans + lower);
        permutationLetterCase(str, ans + upper);
    }
    else{
        permutationLetterCase(str, ans + ch);
    }
    
}

void balPar(int open, int close, string ans){

    if(open == 0 && close == 0){
        cout<<ans<<endl;
        return;
    }
    if(ans.length() == 0){
        balPar(open - 1, close, ans + '(');
    }
    else{
        if(open == 0){
            balPar(open, close - 1, ans + ')');
        }
        else{
            balPar(open - 1, close, ans + '(');
            if(open < close){
                // if open == close it means equal pairs are present and hence you cannot add closing bracket here
                balPar(open, close - 1, ans + ')');
            }
        }
    }
    
}

void binary(int n, string ans, int one, int zero){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }
    if(ans.length() == 0){
        binary(n-1, ans + '1', one + 1, zero);
    }
    else{
        binary(n-1, ans + '1', one + 1, zero);
        if(one > zero){
            binary(n-1, ans + '0', one, zero + 1);
        }
    }
}

void josephus(int k, int idx, vector<int>v, int &ans){
    if(v.size() == 1){
        ans = v[0];
        return;
    }
    idx = (idx + k - 1) % (v.size());
    v.erase(v.begin() + idx);
    josephus(k, idx, v, ans);
}

int main()
{
    string str = "a1B2";
    // printSubsets(str, "");
    // vector<string>ans;
    // printUniqueSubsets(str, "", ans);
    // // if you want to print lexicographically simply sort the array
    // sort(ans.begin(), ans.end());
    // for(auto i : ans){
    //     cout<<i<<endl;
    // }
    // permutationSpaces(str, "");
    // permutationCase(str, "");   
    // assuming the string will always contain small case alphabets
    // permutationLetterCase(str, "");
    // balPar(2, 2, "");
    // binary(3, "", 0, 0);
    vector<int> v;
    for(int i = 0; i < 40; i++){
        v.push_back(i + 1);
    }
    int ans;
    josephus(7, 0, v, ans);
    cout<<ans;
    return 0;
}