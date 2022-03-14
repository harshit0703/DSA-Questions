#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int rows)
{
    if (rows <= 0)
        return {};
    vector<vector<int>> ans(rows);

    for (int i = 0; i < rows; i++)
    {
        ans[i].resize(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++)
        {

            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
    }

    return ans;
}

int main()
{
    // pascal triangle is the sequence of the binomial co-efficients
    // it is basically a 2-d matrix with each row have the same no. of cols
    int n;
    cin >> n;
    vector<vector<int>> ans = generate(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}