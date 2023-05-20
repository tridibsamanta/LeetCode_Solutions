/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 872. Leaf-Similar Trees
~ Link      : https://leetcode.com/problems/leaf-similar-trees/
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
    void getLeafValueSequence(TreeNode *root, vector<int> &seq) {
        if (!root)
            return;

        if (!root -> left && !root -> right) {
            seq.emplace_back(root -> val);
            return;
        }

        getLeafValueSequence(root -> left, seq);
        getLeafValueSequence(root -> right, seq);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValueSeq1, leafValueSeq2;

        getLeafValueSequence(root1, leafValueSeq1);
        getLeafValueSequence(root2, leafValueSeq2);

        return (leafValueSeq1 == leafValueSeq2);
    }
};

// Time Complexity - O(max(n, m))
// Space Complexity - O(max(n, m))
