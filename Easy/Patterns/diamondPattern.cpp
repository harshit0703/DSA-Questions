#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > 0; j--)
        {
            if (j <= i)
                cout << " ";
            else
                cout << "*";
        }

        int afterSpace = i - 1;

        for (int k = 1; k <= 4; k++)
        {
            if (k <= afterSpace)
                cout << " ";
            else
                cout << "*";
        }

        cout << endl;
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (j <= i || j > 9 - i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}