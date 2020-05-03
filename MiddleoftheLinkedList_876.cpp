/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 876. Middle of the Linked List
~ Link      : https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slowPtr = head, *fastPtr = head;
        while (fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
    }
};
