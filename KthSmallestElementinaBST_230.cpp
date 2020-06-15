/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 230. Kth Smallest Element in a BST
~ Link      : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    TreeNode* kthSmallestUtil(TreeNode *root, int k, int &count) {

        if (root == NULL)
            return NULL;

        TreeNode* left = kthSmallestUtil(root -> left, k, count);

        if (left != NULL)
            return left;

        if (++count == k)
            return root;

        return kthSmallestUtil(root -> right, k, count);
    }

    public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *node = kthSmallestUtil(root, k, count);
        return node -> val;
    }
};
