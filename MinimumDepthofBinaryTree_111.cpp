/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 111. Minimum Depth of Binary Tree
~ Link      : https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        if (root -> left == NULL && root -> right == NULL)
            return 1;

        if (!root -> left)
            return minDepth(root -> right) + 1;

        if (!root -> right)
            return minDepth(root -> left) + 1;

        return min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
};
