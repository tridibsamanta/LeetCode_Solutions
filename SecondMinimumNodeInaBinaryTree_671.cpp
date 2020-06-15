/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 671. Second Minimum Node In a Binary Tree
~ Link      : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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

    private:
    void findSecondMinimumValueUtil(TreeNode *root, set<int> &dataset) {
        if (root == NULL)
            return;
        findSecondMinimumValueUtil(root -> left, dataset);
        dataset.emplace(root -> val);
        findSecondMinimumValueUtil(root -> right, dataset);
    }

    public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> dataset;
        findSecondMinimumValueUtil(root, dataset);
        if (dataset.size() < 2)
            return -1;
        else {
            set<int>::iterator itr = dataset.begin();
            return *(++itr);
        }
    }
};
