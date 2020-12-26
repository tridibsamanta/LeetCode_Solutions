/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 95. Unique Binary Search Trees II
~ Link      : https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> generateTreesUtil(int start, int end) {

        vector<TreeNode*> nodes;

        if (start > end) {
            nodes.push_back(NULL);
            return nodes;
        }

        for (int i = start; i <= end; ++i) {

            vector<TreeNode*> left = generateTreesUtil(start, i - 1);
            vector<TreeNode*> right = generateTreesUtil(i + 1, end);

            for (int l = 0; l < left.size(); ++l) {
                for (int r = 0; r < right.size(); ++r) {
                    TreeNode *curr_root = new TreeNode(i, left[l], right[r]);
                    nodes.push_back(curr_root);
                }
            }
        }

        return nodes;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*> ();

        return generateTreesUtil(1, n);
    }
};
