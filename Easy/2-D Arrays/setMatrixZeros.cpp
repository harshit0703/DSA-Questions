#include <bits/stdc++.h>
using namespace std;

void setMatrix(vector<vector<int>> &v)
{
    // we want to achieve this in O(1) space hence we wont use any extra space but instead of that we will be using the first row and col itself as flags

    bool firstCol = false;
    int rows = v.size();
    int cols = v[0].size();

    for (int i = 0; i < rows; i++)
    {
        if (v[i][0] == 0)
            firstCol = true;

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

        if (firstCol)
        {
            v[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}