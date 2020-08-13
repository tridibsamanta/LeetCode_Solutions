/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 987. Vertical Order Traversal of a Binary Tree
~ Link      : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int> > res;

        if (!root)
            return res;

        map<int, map<int, set<int> > > hm;

        queue<pair<TreeNode*, pair<int, int> > > q;
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {

            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();

            TreeNode* currNode = temp.first;
            int column = temp.second.first;
            int level = temp.second.second;

            hm[column][level].insert(currNode -> val);

            if (currNode -> left)
                q.push(make_pair(currNode -> left, make_pair(column - 1, level + 1)));
            if (currNode -> right)
                q.push(make_pair(currNode -> right, make_pair(column + 1, level + 1)));
        }

        for (auto i : hm) {
            vector<int> vertical;

            for (auto j : i.second) {

                for (auto s = j.second.begin(); s != j.second.end(); ++s)
                    vertical.emplace_back(*s);
            }
            res.emplace_back(vertical);
        }

        return res;
    }
};
