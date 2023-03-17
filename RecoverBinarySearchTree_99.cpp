/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 99. Recover Binary Search Tree
~ Link      : https://leetcode.com/problems/recover-binary-search-tree/
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
    TreeNode *prev = NULL, *target1 = NULL, *target2 = NULL;

    void recoverTreeUtil(TreeNode *root) {
        if (!root)
            return;

        recoverTreeUtil(root -> left);

        if (prev != NULL && root -> val < prev -> val) {
            if (!target1)
                target1 = prev;

            target2 = root;
        }

        prev = root;

        recoverTreeUtil(root -> right);
    }

    void recoverTree(TreeNode* root) {
        recoverTreeUtil(root);

        int temp = target1 -> val;
        target1 -> val = target2 -> val;
        target2 -> val = temp;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
