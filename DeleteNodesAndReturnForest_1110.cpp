/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1110. Delete Nodes And Return Forest
~ Link      : https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    unordered_set<int> toDelete;

    TreeNode* delNodesUtil(TreeNode *root, vector<TreeNode*> &res, bool isRoot) {
        if (!root)
            return NULL;

        bool deleteCurrNode = (toDelete.find(root -> val) != toDelete.end());

        if (isRoot && !deleteCurrNode)
            res.emplace_back(root);

        root -> left = delNodesUtil(root -> left, res, deleteCurrNode);
        root -> right = delNodesUtil(root -> right, res, deleteCurrNode);

        return (deleteCurrNode ? NULL : root);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;

        for (int key : to_delete) {
            toDelete.insert(key);
        }

        delNodesUtil(root, res, true);

        return res;
    }
};

// T.C. - O(n)
// S.C. - O(h + n)
