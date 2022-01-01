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
    permutationLetterCase(str, "");
    return 0;
}