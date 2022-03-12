#include <bits/stdc++.h>
using namespace std;

struct student
{
    string id;
    double percent;
    int choices[3];
};

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> seats;
    for (int i = 0; i < c; i++)
    {
        int seat;
        cin >> seat;
        seats.push_back(seat);
    }

    student data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].id;
        cin >> data[i].percent;
        for (int j = 0; j < 3; j++)
        {
            cin >> data[i].choices[j];
        }
    }

    priority_queue<pair<double, string>> ranks;

    return 0;
}