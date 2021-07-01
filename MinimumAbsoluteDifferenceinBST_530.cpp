/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 530. Minimum Absolute Difference in BST
~ Link      : https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    void traverse(TreeNode *root, int &minDiff, int &prevVal) {
        if (!root)
            return;

        traverse(root -> left, minDiff, prevVal);

        if (prevVal != -1) {
            int currDiff = root -> val - prevVal;

            if (currDiff < minDiff)
                minDiff = currDiff;
        }

        prevVal = root -> val;

        traverse(root -> right, minDiff, prevVal);
    }

    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX, prevVal = -1;
        traverse(root, minDiff, prevVal);
        return minDiff;
    }
};

// T.C. - O(n)
// S.C. - O(h)
