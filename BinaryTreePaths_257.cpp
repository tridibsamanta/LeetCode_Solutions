/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 257. Binary Tree Paths
~ Link      : https://leetcode.com/problems/binary-tree-paths/
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

    vector<string> res;

    void RootToLeaf(TreeNode *root, vector<int> path, int pathLen) {
        if (root == NULL)
            return;

        path.push_back(root -> val);
        pathLen++;

        if (root -> left == NULL && root -> right == NULL) {
            string pathStr = "";
            for (int i = 0; i < pathLen; ++i) {
                if (i != (pathLen - 1))
                    pathStr += to_string(path[i]) + "->";
                else
                    pathStr += to_string(path[i]);
            }
            res.emplace_back(pathStr);
        }
        else {
            RootToLeaf(root -> left, path, pathLen);
            RootToLeaf(root -> right, path, pathLen);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        RootToLeaf(root, path, 0);
        return res;
    }
};
