/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 701. Insert into a Binary Search Tree
~ Link      : https://leetcode.com/problems/insert-into-a-binary-search-tree/
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


/* Approach 1 (Recursive) */
/*
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        if (root -> val > val)
            root -> left = insertIntoBST(root -> left, val);
        else if (root -> val < val)
            root -> right = insertIntoBST(root -> right, val);

        return root;
    }
};
*/
// Time Complexity - O(h)
// Space Complexity - O(h)

/* Approach 2 (Iterative) */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        TreeNode *curr = root;

        while (curr) {
            if (curr -> val > val) {
                if (curr -> left)
                    curr = curr -> left;
                else {
                    curr -> left = new TreeNode(val);
                    break;
                }
            }
            else if (curr -> val < val) {
                if (curr -> right)
                    curr = curr -> right;
                else {
                    curr -> right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

// Time Complexity - O(h)
// Space Complexity - O(1)
