#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{

    stack<pair<char, int>> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push({s[i], i});
        }

        else if (s[i] == ')')
        {
            if (st.empty() || st.top().first == ')')
            {
                st.push({s[i], i});
            }

            else
                (st.pop());
        }
    }

    if (st.empty())
        return s;

    multiset<int> mp;
    while (!st.empty())
    {
        mp.insert(st.top().second);
        st.pop();
    }

    string ans = "";

    for (auto i : mp)
        cout << i << endl;

    for (int i = 0; i < s.length(); i++)
    {
        if (mp.count(i) == 0)
        {
            ans += s[i];
        }
    }

    return ans;

    // this way we will be able to find the ans but the code is not optimized properly
}

int main()
{
    cout << minRemoveToMakeValid("a)b(c)d");
    return 0;
}