/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 129. Sum Root to Leaf Numbers
~ Link      : https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    void sumNumbersUtil(TreeNode *root, int &sum, int num) {
        if (!root)
            return;

        num *= 10;
        num += root -> val;

        if (!root -> left && !root -> right)
            sum += num;

        sumNumbersUtil(root -> left, sum, num);
        sumNumbersUtil(root -> right, sum, num);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;

        sumNumbersUtil(root, sum, num);

        return sum;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
