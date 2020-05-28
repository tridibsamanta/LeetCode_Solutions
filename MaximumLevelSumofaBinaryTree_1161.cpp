/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1161. Maximum Level Sum of a Binary Tree
~ Link      : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {

        if (root == NULL)
            return 0;

        int currSum = 0, maxSum = 0, currLevel = 1, maxSumLevel = 1;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {

            TreeNode *temp = q.front();
            q.pop();

            if (!temp) {
                if (currSum > maxSum) {
                    maxSum = currSum;
                    maxSumLevel = currLevel;
                }
                currSum = 0;
                ++currLevel;
                if (!q.empty())
                    q.push(NULL);
            }
            else {
                currSum += temp -> val;

                if (temp -> left)
                    q.push(temp -> left);
                if (temp -> right)
                    q.push(temp -> right);
            }
        }

        return maxSumLevel;
    }
};
