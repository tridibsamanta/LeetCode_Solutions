/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 105. Construct Binary Tree from Preorder and Inorder Traversal
~ Link      : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

    int preIdx = 0;

    int searchNode(vector<int> inorder, int startIdx, int endIdx, int value) {
        for (int i = startIdx; i <= endIdx; ++i)
            if (inorder[i] == value)
                return i;
        return -1;
    }

    TreeNode* buildingTree(vector<int> preorder, vector<int> inorder, int startIdx, int endIdx) {

        if (startIdx > endIdx)
            return NULL;

        TreeNode *newNode = new TreeNode(preorder[preIdx]);
        ++preIdx;

        if (startIdx == endIdx)
            return newNode;

        int inPos = searchNode(inorder, startIdx, endIdx, newNode -> val);

        newNode -> left = buildingTree(preorder, inorder, startIdx, inPos - 1);
        newNode -> right = buildingTree(preorder, inorder, inPos + 1, endIdx);

        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildingTree(preorder, inorder, 0, preorder.size() - 1);
    }
};
