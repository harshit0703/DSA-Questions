#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int>mp;
// we cannot use a 2-d matrix as 3 parameters are changing so we can create a map instead
// the idea is to create a key value pair with all three parameters combined as a string

int evalExp(string str, int i, int j, bool isTrue){

    if(i > j){
        return 0;
    }

    // if there is a single char ans can be based on istrue

    if(i == j){
        if(str[i] == 't'){
            if(isTrue == true){
                return 1;
            }
        }
        else if(str[i] == 'f'){
            if(isTrue == false){
                return 1;
            }
        }
        else{
            return 0;
        }
    }

    string key = "";
    key.append(to_string(i));
    key.append(to_string(j));
    key.append(to_string(isTrue));  // in this way we created a key for the map 

    if(mp.find(key) != mp.end()){
        return mp[key];             // checking for pre existing values inside the map to avoid overlapping cases
    }

    int ans = 0;

    for(int k = i+1; k <= j-1; k = k+2){

        // now we have to make 4 diff calls for every possible outcome

        int LT = evalExp(str, i, k-1, true);
        int LF = evalExp(str, i, k-1, false);
        int RT = evalExp(str, k+1, j, true);
        int RF = evalExp(str, k+1, j, false);

        // now we need to add all the possible ways depending upon the operator

        if(str[k] == '&'){
            if(isTrue == true){
                ans += LT*RT;
            }
            else if(isTrue == false){
                ans += LT*RF + LF*RT + LF*RF;
            }
        }

        else if(str[k] == '|'){
            if(isTrue == true){
                ans += LT*RT + LF*RT + LT*RF;
            }
            else if(isTrue == false){
                ans += LF*RF;
            }
        }

        else if(str[k] == '^'){
            if(isTrue == true){
                ans += LF*RT + LT*RF;
            }
            else if(isTrue == false){
                ans += LT*RT + LF*RF;
            }
        }

    }

    return mp[key] = ans;       // storing values in inside map before returning 

}

int main()
{
    string str = "t|f&t^f";
    mp.clear(); // clears the map so that no value is present before calling the function
    int ans = evalExp(str, 0, str.length()-1, true);
    // this question becomes special because we are using a third parameter in our mcm question
    cout<<ans;
    return 0;
}