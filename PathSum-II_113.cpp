/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 113. Path Sum II
~ Link      : https://leetcode.com/problems/path-sum-ii/
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

    void pathSumUtil(TreeNode* root, int sum, vector<int> path, vector<vector<int> >& res) {

        if (!root)
            return;

        path.emplace_back(root->val);
        sum -= root->val;

        if (sum == 0 && !root->left && !root->right) {
            res.emplace_back(path);
            return;
        }

        pathSumUtil(root->left, sum, path, res);
        pathSumUtil(root->right, sum, path, res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        pathSumUtil(root, sum, path, res);
        return res;
    }
};
