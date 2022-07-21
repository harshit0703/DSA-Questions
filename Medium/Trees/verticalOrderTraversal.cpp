class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        // in vertical order traversal we view our tree as a cartisian plane with root on the origin
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        vector<vector<int>> res;

        while (!q.empty())
        {

            TreeNode *temp = q.front().first;
            int x = q.front().second.first, y = q.front().second.second;
            q.pop();

            if (temp->left)
                q.push({temp->left, {x - 1, y + 1}});
            if (temp->right)
                q.push({temp->right, {x + 1, y + 1}});

            mp[x][y].insert(temp->val);
        }

        for (auto i : mp)
        {
            vector<int> ans;
            for (auto j : i.second)
            {
                ans.insert(ans.end(), j.second.begin(), j.second.end());
            }
            res.push_back(ans);
        }

        return res;
    }
};