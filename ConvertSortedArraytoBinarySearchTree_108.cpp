/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 108. Convert Sorted Array to Binary Search Tree
~ Link      : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    private:
    TreeNode* convertArrayToBST(vector<int> nums, int l, int r) {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (l == r)
            return root;
        root -> left = convertArrayToBST(nums, l, mid - 1);
        root -> right = convertArrayToBST(nums, mid + 1, r);
        return root;
    }

    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertArrayToBST(nums, 0, nums.size() - 1);
    }
};
