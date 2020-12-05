/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
~ Link      : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
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

/* Approach 1 (Using Pre-order Traversal) */
/*
class Solution {
public:
    TreeNode* getTargetCopyUtil(TreeNode* root, int target) {

        if (!root)
            return NULL;

        if (root -> val == target)
            return root;

        TreeNode *left = getTargetCopyUtil(root -> left, target);

        if (left)
            return left;

        return getTargetCopyUtil(root -> right, target);

    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* cloneRef = getTargetCopyUtil(cloned, target -> val);
        return cloneRef;
    }
};
*/

/* Approach 2 (Using Level-order Traversal) */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        if (!cloned)
            return NULL;

        TreeNode *clone_ref = NULL;
        int target_val = target -> val;

        queue<TreeNode*> q;
        q.push(cloned);

        while (!q.empty()) {

            TreeNode *curr = q.front();
            q.pop();

            if (curr -> val == target_val) {
                clone_ref = curr;
                break;
            }

            if (curr -> left)
                q.push(curr -> left);
            if (curr -> right)
                q.push(curr -> right);
        }

        return clone_ref;
    }
};
