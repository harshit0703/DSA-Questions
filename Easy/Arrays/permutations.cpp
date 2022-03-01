#include <bits/stdc++.h>
using namespace std;

void printPermutations(string str, string ans, vector<string> &perm)
{
    // fix the first char and make all possible permutations with the remaining characters
    if (str.length() == 0)
    {
        perm.push_back(ans);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string prev = str.substr(0, i);
        string next = str.substr(i + 1);
        string rest = prev + next;
        printPermutations(rest, ans + ch, perm);
    }
}

int main()
{
    string str = "123";
    vector<string> perm;
    printPermutations(str, "", perm);
    for (int i = 0; i < perm.size(); i++)
    {
        cout << perm[i] << endl;
        if (perm[i] == "321")
        {
            cout << perm[(i + 1) % perm.size()];
        }
    }
    return 0;
}