/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 863. All Nodes Distance K in Binary Tree
~ Link      : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
    unordered_map<int, TreeNode*> parent;

private:
    void getParentOfAllNodes(TreeNode *root, TreeNode *parentNode) {
        if (!root)
            return;

        parent[root -> val] = parentNode;

        getParentOfAllNodes(root -> left, root);
        getParentOfAllNodes(root -> right, root);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;

        getParentOfAllNodes(root, NULL);

        queue<TreeNode*> todo;
        todo.push(target);

        unordered_map<int, bool> visited;
        visited[target -> val] = true;

        while (!todo.empty()) {
            int lvl = todo.size();

            for (int i = 0; i < lvl; ++i) {
                TreeNode *curr = todo.front();
                todo.pop();

                if (k == 0) {
                    res.emplace_back(curr -> val);
                }
                else {
                    TreeNode *currParent = parent[curr -> val];

                    // explore upwards
                    if (currParent != NULL && !visited[currParent -> val]) {
                        todo.push(currParent);
                        visited[currParent -> val] = true;
                    }

                    // explore left child
                    if (curr -> left && !visited[curr -> left -> val]) {
                        todo.push(curr -> left);
                        visited[curr -> left -> val] = true;
                    }

                    // explore right child
                    if (curr -> right && !visited[curr -> right -> val]) {
                        todo.push(curr -> right);
                        visited[curr -> right -> val] = true;
                    }
                }
            }

            if (--k < 0)
                break;
        }

        return res;
    }
};

// T.C. - O(n)
// S.C. - O(n)
