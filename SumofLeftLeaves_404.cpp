/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 404. Sum of Left Leaves
~ Link      : https://leetcode.com/problems/sum-of-left-leaves/
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

// *** BFS Approach *** //
/*
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if (!root || (!root -> left && !root -> right))
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int leftSum = 0;
        while(!q.empty()) {

            TreeNode *currNode = q.front();
            q.pop();

            if (currNode->left) {
                if (!currNode->left->left && !currNode->left->right)
                    leftSum += currNode->left->val;
                q.push(currNode->left);
            }
            if (currNode->right) {
                q.push(currNode->right);
            }
        }

        return leftSum;
    }
};
*/

// *** DFS Approach 1*** //
/*
class Solution {
private:
    void sumOfLeftLeavesUtil(TreeNode* root, int& leftSum) {
        if (!root)
            return;
        if (root-> left && (!root->left->left && !root->left->right))
            leftSum += root->left->val;
        sumOfLeftLeavesUtil(root->left, leftSum);
        sumOfLeftLeavesUtil(root->right, leftSum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int leftSum = 0;
        sumOfLeftLeavesUtil(root, leftSum);
        return leftSum;
    }
};
*/

// *** DFS Approach 2*** //

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;

        if (root -> left && (!root -> left -> left && !root -> left -> right))
            return (root -> left -> val) +  sumOfLeftLeaves(root -> right);

        return sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
    }
};
