/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 124. Binary Tree Maximum Path Sum
~ Link      : https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSumUtil(TreeNode *root, int &res) {
        if (!root)
            return 0;
        int left = maxPathSumUtil(root -> left, res);
        int right = maxPathSumUtil(root -> right, res);
        int max1 = max(root -> val, max(left, right) + root -> val);
        int max2 = max(max1, left + right + root -> val);
        res = max(res, max2);
        return max1;
    }

public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};
