/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 783. Minimum Distance Between BST Nodes
~ Link      : https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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

// Approach 1 (Works for Binary Tree)
/*
class Solution {
public:
    vector<int> values;

    void traverse(TreeNode *root) {
        if (!root)
            return;

        traverse(root -> left);
        values.emplace_back(root -> val);
        traverse(root -> right);
    }

    int minDiffInBST(TreeNode* root) {
        traverse(root);

        sort(values.begin(), values.end());

        int minDiff = INT_MAX;

        for (int i = 1; i < values.size(); ++i) {
            if (values[i] - values[i - 1] < minDiff)
                minDiff = values[i] - values[i - 1];
        }

        return minDiff;
    }
};
*/
// T.C. - O(n log n)
// S.C. - O(n)

// Approach 2 (Using advantage of the fact that the tree is BST)

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

    int minDiffInBST(TreeNode* root) {

        int minDiff = INT_MAX, prevVal = -1;
        traverse(root, minDiff, prevVal);
        return minDiff;
    }
};

// T.C. - O(n)
// S.C. - O(h)
