/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 103. Binary Tree Zigzag Level Order Traversal
~ Link      : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> zz;

        if (root == NULL)
            return zz;

        int direction = 1;

        stack<TreeNode *> currLevel;
        stack<TreeNode *> nextLevel;
        currLevel.push(root);

        vector<int> level;

        while(!currLevel.empty()) {
            TreeNode *temp = currLevel.top();
            currLevel.pop();

            if (temp) {
                level.emplace_back(temp -> val);

                if (direction) {
                    if (temp -> left) nextLevel.push(temp -> left);
                    if (temp -> right) nextLevel.push(temp -> right);
                }
                else {
                    if (temp -> right) nextLevel.push(temp -> right);
                    if (temp -> left) nextLevel.push(temp -> left);
                }
            }
            if (currLevel.empty()) {
                zz.emplace_back(level);
                level.clear();
                swap(currLevel, nextLevel);
                direction = 1 - direction;
            }
        }
        return zz;
    }
};
