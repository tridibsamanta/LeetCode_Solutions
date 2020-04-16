/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 102. Binary Tree Level Order Traversal
~ Link      : https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL)
            return res;

        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            vector<int> level;
            int size = queue.size();
            while(size > 0)
            {
                TreeNode* temp = queue.front();
                queue.pop();
                --size;
                level.push_back(temp->val);
                if(temp->left != NULL)
                    queue.push(temp->left);
                if(temp->right != NULL)
                    queue.push(temp->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
