/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 142. Linked List Cycle II
~ Link      : https://leetcode.com/problems/linked-list-cycle-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {

        if (!head || !head -> next)
            return NULL;

        ListNode *slowPtr = head, *fastPtr = head;

        while (fastPtr && fastPtr -> next) {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;

            if (slowPtr == fastPtr)
                break;
        }

        if (slowPtr != fastPtr)
            return NULL;

        slowPtr = head;

        while (slowPtr != fastPtr) {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next;
        }

        return slowPtr;

    }
};
