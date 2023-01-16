/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 662. Maximum Width of Binary Tree
~ Link      : https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int width = 0;

        queue<pair<TreeNode*, unsigned long long int> > q;
        q.push({root, 0});

        while (!q.empty()) {
            int startIndex = q.front().second;
            int endIndex = q.back().second;

            width = max(width, endIndex - startIndex + 1);

            int levelSize = q.size();

            while (levelSize--) {
                auto curr = q.front();
                q.pop();

                TreeNode *currNode = curr.first;
                unsigned long long int currIndex = curr.second;

                if (currNode -> left)
                    q.push({currNode -> left, 2 * currIndex + 1});

                if (currNode -> right)
                    q.push({currNode -> right, 2 * currIndex + 2});
            }
        }

        return width;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
