#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string str)
{

    string ans, temp;
    vector<string> v;
    stringstream dir(str);
    while (getline(dir, temp, '/'))
    {
        if (temp == "" || temp == ".")
            continue;
        if (temp == ".." && !v.empty())
            v.pop_back();
        else if (temp != "..")
            v.push_back(temp);
    }

    for (auto i : v)
    {
        ans += "/" + i;
    }

    return ans.empty() ? "/" : ans;
}

int main()
{
    string str = "/../harshit/gupta/..////";
    cout << simplifyPath(str);
    return 0;
}