/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 141. Linked List Cycle
~ Link      : https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head;
        while(slowPtr && fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next; // moving one step at a time
            fastPtr = fastPtr->next->next; // moving two steps at a time
            if (slowPtr == fastPtr)
                return true;
        }
        return false;
    }
};
