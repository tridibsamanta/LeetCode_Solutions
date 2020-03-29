/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 98. Validate Binary Search Tree
~ Link      : https://leetcode.com/problems/validate-binary-search-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return IsBstUtil(root,  LLONG_MIN, LLONG_MAX);
    }

    bool IsBstUtil(TreeNode* root, long long int minValue, long long int maxValue) {
        if(root == NULL) return true;
        if((root->val > minValue && root->val < maxValue) && IsBstUtil(root->left, minValue, root->val) && IsBstUtil(root->right, root->val, maxValue))
            return true;
        else
            return false;
    }
};
