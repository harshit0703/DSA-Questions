#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &v)
{

    // first simply find the transpose

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v[0].size(); j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() / 2; j++)
        {
            swap(v[i][j], v[i][v.size() - j - 1]);
        }
    }
}

int main()
{
    // this question is a simple variation to transpose you need good observation skills to see the pattern

    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(v);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}