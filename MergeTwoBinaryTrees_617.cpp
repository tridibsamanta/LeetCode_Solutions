/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 617. Merge Two Binary Trees
~ Link      : https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return NULL;

        if (!root1)
            return root2;
        if (!root2)
            return root1;

        queue<TreeNode*> todo;
        todo.push(root1);
        todo.push(root2);

        TreeNode *mergeRoot = NULL;

        while (!todo.empty()) {
            TreeNode *curr1 = todo.front();
            todo.pop();

            TreeNode *curr2 = todo.front();
            todo.pop();

            curr1 -> val += curr2 -> val;

            if (curr1 -> left && curr2 -> left) {
                todo.push(curr1 -> left);
                todo.push(curr2 -> left);
            }

            if (!curr1 -> left && curr2 -> left)
                curr1 -> left = curr2 -> left;

            if (curr1 -> right && curr2 -> right) {
                todo.push(curr1 -> right);
                todo.push(curr2 -> right);
            }

            if (!curr1 -> right && curr2 -> right)
                curr1 -> right = curr2 -> right;
        }

        return root1;
    }
};

// Time Complexity - O(min(n, m))
// Space Complexity - O(min(n, m))
