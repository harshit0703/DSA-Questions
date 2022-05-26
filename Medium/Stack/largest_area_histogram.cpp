#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // vector containing the heights of the bars
    vector<int> left;                            // for NSL indexes
    vector<int> right;                           // for NSR indexes
    vector<int> width;                           // of the rectangles that can be formed

    stack<pair<int, int>> st;
    int temp_left_idx = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            left.push_back(temp_left_idx);
        }
        else
        {
            while (!st.empty() && st.top().first >= v[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                left.push_back(temp_left_idx);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }
        st.push({v[i], i});
    }
    // after this branch of code we will get the left vector with indexes of NSL

    stack<pair<int, int>> st2;
    int temp_right_idx = v.size();
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (st2.empty())
        {
            right.push_back(temp_right_idx);
        }
        else
        {
            while (!st2.empty() && st2.top().first >= v[i])
            {
                st2.pop();
            }
            if (st2.empty())
            {
                right.push_back(temp_right_idx);
            }
            else
            {
                right.push_back(st2.top().second);
            }
        }
        st2.push({v[i], i});
    }
    reverse(right.begin(), right.end()); // since we are moving from right to left we need to reverse the vector

    for (int i = 0; i < v.size(); i++)
    {
        int n = right[i] - left[i] - 1;
        width.push_back(n);
    }

    int max_area = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int area = width[i] * v[i];
        max_area = max(area, max_area);
    }

    cout << max_area;

    return 0;
}