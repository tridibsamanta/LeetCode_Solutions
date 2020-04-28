/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 19. Remove Nth Node From End of List
~ Link      : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * prevNode = NULL, *temp = head;
        for (int i = 1; i <= n; ++i) {
            temp = temp->next;
        }
        while (temp) {
            if (prevNode == NULL) {
                prevNode = head;
            }
            else
                prevNode = prevNode->next;
            temp = temp->next;
        }
        if (prevNode == NULL) {
            ListNode *temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        ListNode *target = prevNode->next;
        prevNode->next = target->next;
        delete target;
        return head;
    }
};
