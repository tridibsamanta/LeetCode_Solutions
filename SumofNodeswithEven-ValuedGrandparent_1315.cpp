/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1315. Sum of Nodes with Even-Valued Grandparent
~ Link      : https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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

/* Approach 1 (Using BFS) */
/*
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {

        if (!root || (!root -> left && !root -> right))
            return 0;

        int sum = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode *curr = q.front();
            q.pop();

            bool isEvenGrandParent = false;

            if (curr -> val % 2 == 0)
                isEvenGrandParent = true;

            if (curr -> left) {
                q.push(curr -> left);

                if (curr -> left -> left) {
                    if (isEvenGrandParent)
                        sum += curr -> left -> left -> val;
                }

                if (curr -> left -> right) {
                    if (isEvenGrandParent)
                        sum += curr -> left -> right -> val;
                }
            }

            if (curr -> right) {
                q.push(curr -> right);

                if (curr -> right -> left) {
                    if (isEvenGrandParent)
                        sum += curr -> right -> left -> val;
                }

                if (curr -> right -> right) {
                    if (isEvenGrandParent)
                        sum += curr -> right -> right -> val;
                }
            }
        }

        return sum;
    }
};
*/

/* Approach 2 (Using DFS) */

class Solution {
public:
    void sumEvenGrandparentUtil(TreeNode *root, int p_val, int gp_val, int &sum) {

        if (!root)
            return;

        if (gp_val % 2 == 0)
            sum += root -> val;

        sumEvenGrandparentUtil(root -> left, root -> val, p_val, sum);
        sumEvenGrandparentUtil(root -> right, root -> val, p_val, sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        sumEvenGrandparentUtil(root, 1, 1, sum);
        return sum;
    }
};
