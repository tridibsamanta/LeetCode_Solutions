/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 450. Delete Node in a BST
~ Link      : https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            else if(root->left == NULL) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                TreeNode* temp = root->right;
                while(temp->left != NULL)
                    temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
