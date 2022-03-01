#include <bits/stdc++.h>
using namespace std;

void printPascal(int n)
{
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                v[i][j] = 1;
            }
            else if (j == i)
            {
                v[i][j] = 1;
            }
            else
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    printPascal(4);
    return 0;
}