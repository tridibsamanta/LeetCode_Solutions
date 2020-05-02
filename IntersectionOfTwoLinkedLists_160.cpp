/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 160. Intersection of Two Linked Lists
~ Link      : https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *head1 = headA, *head2 = headB;
        int len1 = 0, len2 = 0, diff = 0;
        while(head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        while(head2 != NULL) {
            ++len2;
            head2 =  head2->next;
        }
        if (len1 < len2) {
            head1 = headB; head2 = headA; diff = len2 - len1;
        }
        else {
            head1 = headA; head2 = headB; diff = len1 - len2;
        }
        for (int i = 0; i < diff; ++i)
            head1 = head1->next;
        while (head1 != NULL && head2 != NULL) {
            if (head1 == head2)
                return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return NULL;
    }
};
