#include <bits/stdc++.h>
using namespace std;

class student
{

public:
    string id;
    double percent;
    int choices[3];

    void inputData()
    {
        cin >> id;
        cin >> percent;
        for (int i = 0; i < 3; i++)
        {
            cin >> choices[i];
        }
    }

    void printData()
    {
        cout << id << "->" << percent << "->";
        for (auto i : choices)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{

    int n, c;
    cin >> n >> c;
    int colleges[c];
    for (int i = 0; i < c; i++)
    {
        cin >> colleges[i];
    }

    student obj[n];

    for (int i = 0; i < n; i++)
    {
        obj[i].inputData();
    }

    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     obj[i].printData();
    // }

    // inorder to assign them the correct college we need to prioritize them    according to their percentage

    priority_queue<pair<double, pair<string, vector<int>>>> ranks;
    queue<pair<string, int>> result;

    for (int i = 0; i < n; i++)
    {
        double percentage = obj[i].percent;

        ranks.push({percentage, {obj[i].id, obj[i].choices}});
    }

    while (!ranks.empty())
    {
        auto data = ranks.top();
        ranks.pop();
        int choice1 = data.second.choices[0];
        int choice2 = data.second.choices[1];
        int choice3 = data.second.choices[2];

        for (int i = 0; i < c; i++)
        {
            if (colleges[choice1 - 1] != 0)
            {
                result.push({data.second.id, choice1});
                colleges[choice1 - 1]--;
            }
            else if (colleges[choice2 - 1] != 0)
            {
                result.push({data.second.id, choice2});
                colleges[choice2 - 1]--;
            }
            else if (colleges[choice3 - 1] != 0)
            {
                result.push({data.second.id, choice3});
                colleges[choice3 - 1]--;
            }
        }
    }

    while (!result.empty())
    {
        auto i = result.front();
        cout << i.first << " " << i.second << endl;
        result.pop();
    }

    return 0;
}