/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 114. Flatten Binary Tree to Linked List
~ Link      : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {

        TreeNode *curr = root;

        while (curr != NULL) {

            if (curr -> left != NULL) {

                TreeNode *temp = curr -> left;

                while (temp -> right != NULL)
                    temp = temp -> right;

                temp -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = nullptr;
            }
            curr = curr -> right;
        }
    }
};

/*
class Solution {
public:
    TreeNode *next = NULL;
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root -> right);
        flatten(root -> left);
        root -> left = NULL;
        root -> right = next;
        next = root;
    }
};
*/
