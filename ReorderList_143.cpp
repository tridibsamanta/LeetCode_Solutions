/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 143. Reorder List
~ Link      : https://leetcode.com/problems/reorder-list/
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

    void reverseList(ListNode **head2) {
    ListNode *prev = NULL, *curr = *head2, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head2 = prev;
    }

    void reorderList(ListNode* head) {

    if (head == NULL || head->next == NULL)
            return;

    // 1. Find the middle of the list using the slow and fast pointer approach
    ListNode *slowPtr = head, *fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // 2. Split the linked list into two halves
    ListNode *head1 = head;
    ListNode *head2 = slowPtr->next;
    slowPtr->next = NULL;

    // 3. Reverse the second half
    reverseList(&head2);

    // 4. Form the new list by taking one node alternately from list 1 & list 2
    ListNode *temp = new ListNode(0);
    head = temp;
    ListNode *curr = head;

    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2!= NULL) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    head = head->next;
    delete temp;
    }
};
