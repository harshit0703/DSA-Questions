#include<bits/stdc++.h>
using namespace std;

int findAnagrams(string str, string pattern){
    // at first we need to create a map to hold the char in pattern with their count and for this we will need a map
    map<char, int> m;
    
    for(auto ele: pattern){
        m[ele]++;   // in this way we stored the chars with their count inside the map
    }

    int count = m.size();       // number of distinct char in pattern
    int ans = 0;
    int k = pattern.length();   // window size

    int i = 0;
    int j = 0;

    while(j < str.length()){
        
        if(m.find(str[j]) != m.end()){
            m[str[j]]--;
            if(m[str[j]] == 0){
                count--;
            }
        }

        if(j - i + 1 < k){
            j++;
        }
        else if( j - i + 1 == k){
            if(count == 0){
                ans++;
            }
            if(m.find(str[i]) !=  m.end()){
                m[str[i]]++;
                if( m[str[i]] == 1){
                    count++;
                }
            }
        }
        i++;
        j++;
    }
    return ans;
}

int main()
{
    // anagrams are all possible jumbled combinations of a given string 
    // hence a string with n char = n! anagrams
    string str = "forxxorfxdofr";
    string pattern = "for";
    int ans = findAnagrams(str, pattern);
    cout<<ans;
    return 0;
}