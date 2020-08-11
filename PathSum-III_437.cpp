/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 437. Path Sum III
~ Link      : https://leetcode.com/problems/path-sum-iii/
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
private:
    void pathSumUtil(TreeNode* root, int sum, vector<int> path, int &pathCount) {

        if (!root)
            return;

        path.emplace_back(root->val);

        pathSumUtil(root->left, sum, path, pathCount);
        pathSumUtil(root->right, sum, path, pathCount);

        int currPathSum = 0;

        for (int i = path.size() - 1; i >= 0; --i) {
            currPathSum += path[i];
            if (currPathSum == sum)
                ++pathCount;
        }
    }
public:
    int pathSum(TreeNode* root, int sum) {
        int pathCount = 0;
        vector<int> path;
        pathSumUtil(root, sum, path, pathCount);
        return pathCount;
    }
};
