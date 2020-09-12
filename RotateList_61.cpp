/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 61. Rotate List
~ Link      : https://leetcode.com/problems/rotate-list/
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head)
            return NULL;

        int nodeCount = 1;

        ListNode* curr = head;

        while (curr -> next != NULL) {
            ++nodeCount;
            curr = curr -> next;
        }

        k %= nodeCount;

        if (k == 0)
            return head;

        curr -> next = head;

        k = nodeCount - k;
        while (k--) {
            curr = curr -> next;
        }

        head = curr -> next;
        curr -> next = NULL;

        return head;
    }
};
