/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 110. Balanced Binary Tree
~ Link      : https://leetcode.com/problems/balanced-binary-tree/
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
    int isBalancedUtil(TreeNode* root) {

        if (root == NULL)
            return 0;

        int lh = isBalancedUtil(root -> left);
        if (lh == -1)
            return -1;

        int rh = isBalancedUtil(root -> right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return max(lh, rh) + 1;
    }

    public:
    bool isBalanced(TreeNode* root) {

        if(isBalancedUtil(root) == -1)
            return false;
        else
            return true;
    }
};
