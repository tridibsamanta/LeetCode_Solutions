/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 669. Trim a Binary Search Tree
~ Link      : https://leetcode.com/problems/trim-a-binary-search-tree/
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {

        if (!root)
            return NULL;

        if (root -> val > R)
            return trimBST(root -> left, L, R);
        if (root -> val < L)
            return trimBST(root -> right, L, R);

        root -> left = trimBST(root -> left, L, R);
        root -> right = trimBST(root -> right, L, R);

        return root;
    }
};
