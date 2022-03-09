#include <bits/stdc++.h>
using namespace std;

int LCseq(vector<int> nums)
{

    set<int> hashset;
    for (int i : nums)
        hashset.insert(i);

    int ans = 0;

    for (int i : nums)
    {
        // we need to make sure it is the start of the sequence by making sure its predecessor is not present in the set
        if (!hashset.count(i - 1))
        {
            int curr = i;
            int currLen = 1;

            while (hashset.count(curr + 1))
            {
                curr++;
                currLen++;
            }

            ans = max(currLen, ans);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << LCseq(nums);
    return 0;
}