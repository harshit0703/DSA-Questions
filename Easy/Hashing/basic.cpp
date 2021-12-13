#include<bits/stdc++.h>
using namespace std;

bool hashTable[2][1000];    // hashtable for mappnig complex keys to simple ones

void insert(vector<int>v){  // hash function
    
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] >= 0){
            hashTable[0][v[i]] = true;
        }else{
            hashTable[1][abs(v[i])] = true;
        }
    }
    

}

bool search(int n){
    if(n >= 0){
        return hashTable[0][n];
    }
    else{
        return hashTable[1][abs(n)];
    }
}

int main()
{
    vector<int> arr = {1, 3, 4, -3, -5, -7, 9};
    insert(arr);
    cout<<search(4);
    return 0;
}