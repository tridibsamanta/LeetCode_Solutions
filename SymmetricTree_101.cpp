/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 101. Symmetric Tree
~ Link      : https://leetcode.com/problems/symmetric-tree/
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

/***** Approach 1 (Recursive) *****/

class Solution {
public:
    bool isSymmetricUtil(TreeNode* root1, TreeNode* root2) {

        if (!root1 && !root2)
            return true;

        if (root1 && root2 && (root1 -> val == root2 -> val))
            return isSymmetricUtil(root1 -> left, root2 -> right) &&
                    isSymmetricUtil(root1 -> right, root2 -> left);

        return false;
    }

    bool isSymmetric(TreeNode* root) {

        if (!root)
            return true;

        return isSymmetricUtil(root -> left, root -> right);
    }
};


/***** Approach 2 (Iterative) *****/
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root -> left);
        q.push(root -> right);

        while (!q.empty()) {

            TreeNode *curr1 = q.front();
            q.pop();
            TreeNode *curr2 = q.front();
            q.pop();

            if (!curr1 && !curr2)
                continue;

            if (!curr1 || !curr2)
                return false;

            if (curr1 -> val != curr2 -> val)
                return false;

            q.push(curr1 -> left); q.push(curr2 -> right);
            q.push(curr1 -> right); q.push(curr2 -> left);
        }

        return true;
    }
};
*/
