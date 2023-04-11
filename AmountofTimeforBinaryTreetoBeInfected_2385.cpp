/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2385. Amount of Time for Binary Tree to Be Infected
~ Link      : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
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
    unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode *startNode;

    void getParent(TreeNode *root, TreeNode *parent, int start) {
        if (!root)
            return;

        if (root -> val == start)
            startNode = root;

        parentMap[root] = parent;

        getParent(root -> left, root, start);
        getParent(root -> right, root, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        getParent(root, NULL, start);

        queue<TreeNode*> todo;
        todo.push(startNode);

        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;

        int minutesElapsed = 0;

        while (!todo.empty()) {

            int levelSize = todo.size();

            while (levelSize--) {
                TreeNode *curr = todo.front();
                todo.pop();

                TreeNode *parentNode = parentMap[curr];

                if (parentNode && !visited[parentNode]) {
                    todo.push(parentNode);
                    visited[parentNode] = true;
                }

                if (curr -> left && !visited[curr -> left]) {
                    todo.push(curr -> left);
                    visited[curr -> left] = true;
                }

                if (curr -> right && !visited[curr -> right]) {
                    todo.push(curr -> right);
                    visited[curr -> right] = true;
                }
            }

            if (todo.size())
                ++minutesElapsed;
        }

        return minutesElapsed;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
