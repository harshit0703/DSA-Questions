#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string str)
{
    stack<int> st;
    int score = 0;

    for (auto i : str)
    {
        if (i == '(')
        {
            st.push(score);
            score = 0;
        }

        else
        {
            score = st.top() + max(2 * score, 1);
            st.pop();
        }
    }

    return score;
}

int main()
{
    cout << scoreOfParentheses("(((()()))())");
    return 0;
}