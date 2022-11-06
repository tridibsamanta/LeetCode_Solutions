/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 988. Smallest String Starting From Leaf
~ Link      : https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    string letter = "abcdefghijklmnopqrstuvwxyz";

    void smallestFromLeaf(TreeNode *root, string curr, string &res) {
        if (!root)
            return;

        curr.push_back(letter[root -> val]);

        if (!root -> left && !root -> right) {
            reverse(curr.begin(), curr.end());

            if (res.empty() || curr < res)
                res = curr;
        }

        smallestFromLeaf(root -> left, curr, res);
        smallestFromLeaf(root -> right, curr, res);
    }

    string smallestFromLeaf(TreeNode* root) {
        string res = "", curr = "";

        smallestFromLeaf(root, curr, res);

        return res;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
