/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 652. Find Duplicate Subtrees
~ Link      : https://leetcode.com/problems/find-duplicate-subtrees/
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
    string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*> > &ump) {
        if (!root)
            return "";

        string left = dfs(root -> left, ump);
        string right = dfs(root -> right, ump);

        string curr = to_string(root -> val) + "L" + left + "R" + right;

        ump[curr].emplace_back(root);

        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, vector<TreeNode*> > ump;

        dfs(root, ump);

        for (auto kv : ump) {
            if (kv.second.size() > 1)
                res.emplace_back(kv.second[0]);
        }

        return res;
    }
};

// Time Complexity - O(n^2)
// Auxiliary Space - O(n^2)
