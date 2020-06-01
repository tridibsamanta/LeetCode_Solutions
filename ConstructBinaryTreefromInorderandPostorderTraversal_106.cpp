/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 106. Construct Binary Tree from Inorder and Postorder Traversal
~ Link      : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

    int postIdx = 0;

    int searchNode(vector<int> inorder, int start, int end, int value) {
        for (int i = start; i <= end; ++i)
            if (inorder[i] == value)
                return i;
        return -1;
    }

    TreeNode* buildTreeHelper(vector<int> inorder, vector<int> postorder, int startIdx, int endIdx) {

        if (startIdx > endIdx)
            return NULL;

        TreeNode *newNode = new TreeNode(postorder[postIdx--]);

        if (startIdx == endIdx)
            return newNode;

        int pos = searchNode(inorder, startIdx, endIdx, newNode -> val);

        newNode -> right = buildTreeHelper(inorder, postorder, pos + 1, endIdx);
        newNode -> left = buildTreeHelper(inorder, postorder, startIdx, pos - 1);

        return newNode;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};
