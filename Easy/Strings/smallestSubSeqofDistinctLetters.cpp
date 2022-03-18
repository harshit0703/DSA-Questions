#include <bits/stdc++.h>
using namespace std;

bool isValid(string str, string ans)
{
    int i = 0, j = 0;
    while (i < str.length() && j < ans.length())
    {
        if (str[i] == ans[j])
            j++;
        i++;
    }

    if (j == ans.length())
        return true;

    return false;
}

void solve(string str, string ans, string &given, string &res)
{
    if (str.length() == 0)
    {
        if (isValid(given, ans) && res.length() == 0)
        {
            res = ans;
            return;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        string prev = str.substr(0, i);
        string next = str.substr(i + 1);
        string ros = prev + next;

        solve(ros, ans + str[i], given, res);
    }
}

int main()
{
    string given = "bcabcdefghijklmnopqrstuv";
    string res = "";
    solve("abc", "", given, res);
    cout << res;
    return 0;
}