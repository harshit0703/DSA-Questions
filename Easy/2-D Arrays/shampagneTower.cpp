#include <bits/stdc++.h>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{

    vector<vector<int>> tower(query_row);

    for (int i = 0; i <= query_row; i++)
    {
        tower[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                tower[i][j] = 1;
            }
            else
            {
                tower[i][j] = tower[i - 1][j] + tower[i - 1][j - 1];
            }
        }
    }

    int remaining = poured;
    int ending_row = 0;
    double rational = 0;
    double ans = 0;

    for (int i = 0; i <= query_row; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += tower[i][j];
        }
        if (remaining < sum)
        {
            ending_row = i;
            rational = remaining / sum;
            break;
        }
        else
        {
            remaining -= sum;
        }
    }

    if (query_row < ending_row)
    {
        return 1;
    }
    else if (query_row > ending_row)
    {
        return 0;
    }
    else
    {
        ans = tower[query_row][query_glass] * rational;
    }

    return ans;
}

int main()
{
    cout << champagneTower(4, 2, 2);
    return 0;
}

// --------------------------solution on leetcode-----------------------------

// double champagneTower(int poured, int query_row, int query_glass)
// {

//     double tower[101][101] = {0};

//     tower[0][0] = poured;

//     for (int i = 0; i < 100; i++)
//     {
//         for (int j = 0; j < 100; j++)
//         {
//             if (tower[i][j] > 1)
//             {
//                 tower[i + 1][j] += (tower[i][j] - 1) / 2;
//                 tower[i + 1][j + 1] += (tower[i][j] - 1) / 2;
//                 tower[i][j] = 1;
//             }
//         }
//     }

//     return tower[query_row][query_glass];
// }