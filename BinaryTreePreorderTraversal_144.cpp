/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 144. Binary Tree Preorder Traversal
~ Link      : https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/
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

    void traversePreorder(TreeNode* root) {
        if (!root)
            return;

        values.emplace_back(root -> val);
        traversePreorder(root -> left);
        traversePreorder(root -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        traversePreorder(root);
        return values;
    }
};

// T.C. - O(n)
// S.C. - O(n)
