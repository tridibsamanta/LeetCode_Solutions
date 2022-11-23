/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 337. House Robber III
~ Link      : https://leetcode.com/problems/house-robber-iii/
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
    int robUtil(TreeNode *root, unordered_map<TreeNode*, int> &loot) {
        if (!root)
            return 0;

        if (loot.count(root))
            return loot[root];

        // rob current house
        int currLoot1 = root -> val;

        if (root -> left)
            currLoot1 += robUtil(root -> left -> left, loot) +
                         robUtil(root -> left -> right, loot);

        if (root -> right)
            currLoot1 += robUtil(root -> right -> left, loot) +
                         robUtil(root -> right -> right, loot);

        // don't rob current house
        int currLoot2 = 0;

        currLoot2 += robUtil(root -> left, loot) + robUtil(root -> right, loot);

        return loot[root] = max(currLoot1, currLoot2);
    }

    int rob(TreeNode* root) {
        if (!root)
            return 0;

        if (!root -> left && !root -> right)
            return (root -> val);

        unordered_map<TreeNode*, int> loot;

        return robUtil(root, loot);
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
