#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &v)
{
    // we need to take advantage of the fact to check zeros must be present inside the first row or col
    // we are using the first row and col as dummy arrays to check if the val will be zero or not
    // since the v[0][0] will be overlapping we will be using a seperate variable to check the same

    bool col0 = false;

    int rows = v.size();
    int cols = v[0].size();

    for (int i = 0; i < rows; i++)
    {
        if (v[i][0] == 0)
            col0 = true;
        for (int j = 1; j < cols; j++)
        {

            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }

        if (col0 == true)
        {
            v[i][0] = 0;
        }
    }
}

int main()
{
    // given a m*n matrix if we found a zero we need to change the whole col and row to zero
    // we must do it in inplace which means no extra space

    vector<vector<int>> v = {{0, 1, 3, 0}, {3, 4, 5, 1}, {1, 3, 1, 5}};

    setZeros(v);

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