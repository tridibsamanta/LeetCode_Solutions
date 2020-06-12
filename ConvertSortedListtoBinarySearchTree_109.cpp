/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 109. Convert Sorted List to Binary Search Tree
~ Link      : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    vector<int> values;

    void formArray(ListNode *head) {
        if (!head)
            return;
        ListNode *temp = head;
        while (temp != NULL) {
            values.emplace_back(temp -> val);
            temp = temp -> next;
        }
    }

    TreeNode* convertLLToBST(int l, int r) {

        if (l > r)
            return NULL;

        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(values[mid]);

        if (l == r)
            return root;

        root -> left = convertLLToBST(l, mid - 1);
        root -> right = convertLLToBST(mid + 1, r);
        return root;
    }

    public:
    TreeNode* sortedListToBST(ListNode* head) {
        formArray(head);
        return convertLLToBST(0, values.size() - 1);
    }
};


/*
class Solution {
    private:
    ListNode* findMiddleElement(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head, *prevPtr = NULL;
        while (fastPtr != NULL && fastPtr -> next != NULL) {
            prevPtr = slowPtr;
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }
        if (prevPtr != NULL)
            prevPtr -> next = NULL;
        return slowPtr;
    }
    public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (head == NULL)
            return NULL;

        ListNode *mid = findMiddleElement(head);
        TreeNode *root = new TreeNode(mid -> val);

        if(head == mid)
            return root;

        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(mid -> next);
        return root;
    }
}; */
