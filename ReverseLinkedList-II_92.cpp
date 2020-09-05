/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 92. Reverse Linked List II
~ Link      : https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode *prev = NULL, *curr = head, *next = NULL;

        while (m > 1) {
            prev = curr;
            curr = curr -> next;
            --m;
            --n;
        }

        ListNode *prev_start = prev, *start = curr;

        while (n--) {

            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;

        }

        if (prev_start != NULL)
            prev_start -> next = prev;
        else
            head = prev;

        start -> next = curr;

        return head;
    }
};
