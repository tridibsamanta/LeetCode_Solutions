/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1372. Longest ZigZag Path in a Binary Tree
~ Link      : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
    int longestZigZag(TreeNode* root) {
        if (!root || (!root -> left && !root -> right))
            return 0;

        int longestPath = 0;

        queue<pair<TreeNode*, pair<char, int> > > todo;
        todo.push({root, {'L', 0}});

        while (!todo.empty()) {
            auto curr = todo.front();
            todo.pop();

            TreeNode *currNode = curr.first;
            char direction = curr.second.first;
            int pathSize = curr.second.second;

            longestPath = max(longestPath, pathSize);

            if (currNode -> left) {
                if (direction == 'R')
                    todo.push({currNode -> left, {'L', pathSize + 1}});
                else
                    todo.push({currNode -> left, {'L', 1}});
            }

            if (currNode -> right) {
                if (direction == 'L')
                    todo.push({currNode -> right, {'R', pathSize + 1}});
                else
                    todo.push({currNode -> right, {'R', 1}});
            }
        }

        return longestPath;
    }
};
*/
// Time Complexity - O(n)
// Space Complexity - O(n)

/* Approach 2 (Using DFS) */

class Solution {
public:
    int longestZigZagUtil(TreeNode *root, bool isRight, int &longestPath) {
        if (!root)
            return 0;

        int l = longestZigZagUtil(root -> left, false, longestPath);
        int r = longestZigZagUtil(root -> right, true, longestPath);

        longestPath = max(longestPath, max(l, r));

        return (isRight ? l + 1 : r + 1);
    }

    int longestZigZag(TreeNode* root) {
        if (!root || (!root -> left && !root -> right))
            return 0;

        int longestPath = 0;

        // false -> current node is the left child of its parent
        // true -> current node is the right child of its parent

        longestZigZagUtil(root, false, longestPath);

        return longestPath;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(h)
