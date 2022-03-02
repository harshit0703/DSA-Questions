#include <bits/stdc++.h>
using namespace std;

bool isSubSeq(string str, string ans, string &check)
{
    if (str.length() == 0)
    {
        return (check == ans);
    }

    char ch = str[0];
    str = str.substr(1);
    return (isSubSeq(str, ans + ch, check) || isSubSeq(str, ans, check));
}

int main()
{
    string check = "ab";
    cout << isSubSeq("abc", "", check);
    return 0;
}