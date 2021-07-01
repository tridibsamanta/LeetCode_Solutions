/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 145. Binary Tree Postorder Traversal
~ Link      : https://leetcode.com/problems/binary-tree-postorder-traversal/
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

    void traversePostorder(TreeNode* root) {
        if (!root)
            return;

        traversePostorder(root -> left);
        traversePostorder(root -> right);
        values.emplace_back(root -> val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        traversePostorder(root);
        return values;
    }
};

// T.C. - O(n)
// S.C. - O(n)
