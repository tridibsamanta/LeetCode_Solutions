/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 236. Lowest Common Ancestor of a Binary Tree
~ Link      : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root -> left, p, q);
        TreeNode *right = lowestCommonAncestor(root -> right, p, q);

        if (left && right)
            return root;

        return (left != NULL) ? left : right;
    }
};
