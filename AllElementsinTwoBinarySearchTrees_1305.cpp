/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1305. All Elements in Two Binary Search Trees
~ Link      : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
    void getAllNodeValues(TreeNode *root, vector<int> &values) {
        if (!root)
            return;

        getAllNodeValues(root -> left, values);
        values.emplace_back(root -> val);
        getAllNodeValues(root -> right, values);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res, values1, values2;

        getAllNodeValues(root1, values1);
        getAllNodeValues(root2, values2);

        int n = values1.size(), index1 = 0;
        int m = values2.size(), index2 = 0;

        while (index1 < n && index2 < m) {
            if (values1[index1] <= values2[index2])
                res.emplace_back(values1[index1++]);
            else
                res.emplace_back(values2[index2++]);
        }

        while (index1 < n) {
            res.emplace_back(values1[index1++]);
        }

        while (index2 < m) {
            res.emplace_back(values2[index2++]);
        }

        return res;
    }
};

// Time Complexity - O(n + m)
// Auxiliary Space - O(n + m)
