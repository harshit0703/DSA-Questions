#include <bits/stdc++.h>
using namespace std;

string smallestSubSeq(string str)
{
    // we will be requiring multiple items
    // a cnt array to store the frequency of the elements in the string
    // a visited array to make sure which elements are present in the stack
    // a stack to make sure the given sub seq is lexicographically smallest possible

    vector<int> cnt(26, 0);
    vector<int> visited(26, 0);
    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        cnt[str[i] - 'a']++;
    }

    for (int i = 0; i < str.size(); i++)
    {
        cnt[str[i] - 'a']--;
        // to decrease the number of elements present inside the remaining string

        if (visited[str[i] - 'a'] == 1)
            continue;
        // if already present in the array we dont need to do anything

        while (!st.empty() && st.top() > str[i] && cnt[st.top() - 'a'] != 0)
        {
            // we can remove the elements from the stack which are bigger than the current element and are also present after  this element inside the string
            visited[st.top() - 'a'] = 0;
            st.pop();
        }
        visited[str[i] - 'a'] = 1;
        st.push(str[i]);
    }

    string ans = "";

    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main()
{
    cout << smallestSubSeq("cbacdcbc");
    return 0;
}