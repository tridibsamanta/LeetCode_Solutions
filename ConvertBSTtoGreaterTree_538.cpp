/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 538. Convert BST to Greater Tree
~ Link      : https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    void convertBSTToGreater(TreeNode *root, int &sum) {
        if (!root)
            return;

        convertBSTToGreater(root -> right, sum);

        sum += root -> val;
        root -> val = sum;

        convertBSTToGreater(root -> left, sum);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root || (!root -> left && !root -> right))
            return root;

        int sum = 0;
        convertBSTToGreater(root, sum);

        return root;
    }
};

// T.C. - O(n)
// S.C. - O(n)
