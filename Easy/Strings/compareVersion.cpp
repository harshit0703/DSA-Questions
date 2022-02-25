#include<bits/stdc++.h>
using namespace std;

int compareVer(string version1, string version2){

    // the max no of dots will provide the total number of comparisons
    int dots1 = 0, dots2 = 0;

    for (int i = 0; i < version1.length(); i++)
    {
        if (version1[i] == '.')
            dots1++;
    }

    cout << dots1 << endl;

    for (int i = 0; i < version2.length(); i++)
    {
        if (version2[i] == '.')
            dots2++;
    }

    cout << dots2 << endl;

    // if any of them do not contain any number of dots append a .0 at the end so that the last string after dot will always be 0

    if(dots1 == 0) version1.append(".0");
    if(dots2 == 0) version2.append(".0");

    stringstream ver1(version1);
    stringstream ver2(version2);

    string a, b;

    int versions = max(dots1, dots2);

    int i = 0;

    int ans = 0;

    while(i <= versions){

        getline(ver1, a, '.');
        getline(ver2, b, '.');

        int j = 0;
        while(a[j] == '0' && j < a.length())j++;
        if(j == a.length()) a = "0";
        else a = a.substr(j);

        int k = 0;
        while(b[k] == '0' && k < b.length())k++;
        if(k == b.length()) b = "0";
        else b = b.substr(k);

        cout<<a<<" "<<b<<endl;

        if(stoi(a) > stoi(b)){
            ans = 1;
            break;
        } else if(stoi(b) > stoi(a)){
            ans = -1;
            break;
        }

        i++;

    }

    return ans;
}

int solve(string version1, string version2){
    int i = 0;
    int j = 0;

    int stV1 = 0;
    int stV2 = 0;

    string a, b;
    int ans = 0;

    while(i < version1.length() || j < version2.length()){

        while(version1[i] != '.' && i < version1.length()) i++;
        if(stV1 == version1.length()){
            a = "0";
        }else{
            a = version1.substr(stV1, i);
            stV1 = i + 1;
            i++;
        }
       

        while(version2[j] != '.' && j < version2.length()) j++;
        if(stV2 == version2.length()){
            b = "0";
        }else{
            b = version2.substr(stV2, j);
            stV2 = j+1;
            j++;
        }

        cout<<a<<" "<<b<<endl;
        

        if(stoi(a) > stoi(b)){
            ans = 1;
            break;
        }

        if(stoi(b) > stoi(a)){
            ans = -1;
            break;
        }

    }

    return ans;
}

int main()
{
    string version1 = "1.1";
    string version2 = "1.01.0";
    cout<<solve(version1, version2);
    return 0;
}