#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int n = pushed.size();

    int i = 0, j = 0;

    stack<int> st;

    while (i < n)
    {
        st.push(pushed[i++]);
        if (st.top() == popped[j])
        {
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
    }

    while (!st.empty() && popped[j] == st.top())
    {
        st.pop();
        j++;
    }

    return (st.size() == 0);
}

int main()
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};
    cout << validateStackSequences(pushed, popped);
    return 0;
}