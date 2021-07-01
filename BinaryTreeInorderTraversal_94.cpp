/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 94. Binary Tree Inorder Traversal
~ Link      : https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> values;

    void traverseInorder(TreeNode* root) {
        if (!root)
            return;

        traverseInorder(root -> left);
        values.emplace_back(root -> val);
        traverseInorder(root -> right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        traverseInorder(root);
        return values;
    }
};

// T.C. - O(n)
// S.C. - (n)
