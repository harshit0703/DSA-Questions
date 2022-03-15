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

string minRemoveToMakeValidOpt(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            if (st.empty())
                s[i] = '#';
            else
                st.pop();
        }
    }

    while (!st.empty())
    {
        s[st.top()] = '#';
        st.pop();
    }

    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '#')
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
    // by making them # we dont need to use any other vector or multiset to find the indexes of invalid parenthesis
}

// we can also perform this in O(1) space without using any extra space and simply counting the number of parenthesis

string minRemoveToMakeValidMoreOpt(string s)
{

    int count = 0;
    // for storing the number of open brackets

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
        {
            if (count == 0)
            {
                s[i] = '#';
            }
            else
                count--;
        }
    }

    // by doing so we make sure to eliminate all the invalid open brackets

    // similarly we can also eliminate the closed brackets by travelling in reverse dir

    count = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            count++;
        else if (s[i] == '(')
        {
            if (count == 0)
            {
                s[i] = '#';
            }
            else
                count--;
        }
    }

    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '#')
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

int main()
{
    cout << minRemoveToMakeValid("a)b(c)d") << endl;
    cout << minRemoveToMakeValidOpt("a)b(c)d") << endl;
    cout << minRemoveToMakeValidMoreOpt("a)b(c)d") << endl;

    return 0;
}