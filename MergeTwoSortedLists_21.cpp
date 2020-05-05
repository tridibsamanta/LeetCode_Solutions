/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 21. Merge Two Sorted Lists
~ Link      : https://leetcode.com/problems/merge-two-sorted-lists/
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

// Recursive Approach

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val <= l2->val) {
            l3 = l1;
            l3->next = mergeTwoLists(l1->next, l2);
        }
        else {
            l3 = l2;
            l3->next = mergeTwoLists(l1, l2->next);
        }
        return l3;
    }
};
*/

// Iterative Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *temp1 = l1, *temp2 = l2, *result = NULL;

        if (temp1->val <= temp2->val) {
            result = temp1;
            temp1 = temp1->next;
        }
        else {
            result = temp2;
            temp2 = temp2->next;
        }

        ListNode *temp3 = result;

        while (temp1 != NULL && temp2 != NULL) {

            if (temp1->val <= temp2->val) {
                temp3->next = temp1;
                temp3 = temp3->next;
                temp1 = temp1->next;
            }
            else {
                temp3->next = temp2;
                temp3 = temp3->next;
                temp2 = temp2->next;
            }
        }

        if (temp1 != NULL)
            temp3->next = temp1;
        else
            temp3->next = temp2;

        return result;
    }
};
