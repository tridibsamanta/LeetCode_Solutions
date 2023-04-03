/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 687. Longest Univalue Path
~ Link      : https://leetcode.com/problems/longest-univalue-path/
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
    int longestUnivaluePathUtil(TreeNode *root, int &longestPathLen) {
        if (!root)
            return 0;

        int leftPathLen = longestUnivaluePathUtil(root -> left, longestPathLen);
        int rightPathLen = longestUnivaluePathUtil(root -> right, longestPathLen);

        bool extendLeft = false; // can we add current node with left subtree path
        bool extendRight = false; // can we add current node with right subtree path

        if (!root -> left)
            leftPathLen = 0;
        else if (root -> val == root -> left -> val) {
            ++leftPathLen; // add the edge joining current node and its left child
            extendLeft = true;
        }

        if (!root -> right)
            rightPathLen = 0;
        else if (root -> val == root -> right -> val) {
            ++rightPathLen; // add the edge joining current node and its right child
            extendRight = true;
        }

        if (extendLeft && extendRight) {
            longestPathLen = max(longestPathLen, leftPathLen + rightPathLen);
            return max(leftPathLen, rightPathLen);
        }
        else if (extendLeft) {
            longestPathLen = max(longestPathLen, leftPathLen);
            return leftPathLen;
        }
        else if (extendRight) {
            longestPathLen = max(longestPathLen, rightPathLen);
            return rightPathLen;
        }

        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        int longestPathLen = 0;
        longestUnivaluePathUtil(root, longestPathLen);
        return longestPathLen;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
