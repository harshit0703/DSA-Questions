#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we will be given with a vector in which only one element will be repeating multiple times we need to find this element without using any extra space and without changing the vector i.e we cannot sort the vector

    vector<int> v = {3, 1, 3, 4, 2};

    // this is the same method we used in cycle detection in linkedLists

    int turtle = v[0];
    int rabbit = v[0];

    do
    {
        turtle = v[turtle];
        rabbit = v[v[rabbit]];
    } while (turtle != rabbit);

    turtle = v[0];

    while (turtle != rabbit)
    {
        turtle = v[turtle];
        rabbit = v[rabbit];
    }

    cout << rabbit;

    return 0;
}