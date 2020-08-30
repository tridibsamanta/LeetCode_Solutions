/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 148. Sort List
~ Link      : https://leetcode.com/problems/sort-list/
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
private:
    ListNode* sortedMerge(ListNode *list1, ListNode *list2) {

        ListNode *mergedList = NULL;

        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val <= list2->val) {
            mergedList = list1;
            mergedList->next = sortedMerge(list1->next, list2);
        }
        else {
            mergedList = list2;
            mergedList->next = sortedMerge(list1, list2->next);
        }

        return mergedList;
    }

    void splitList(ListNode *head, ListNode **l1Head, ListNode **l2Head) {

        ListNode *slowPtr = head, *fastPtr = head;

        while (!fastPtr && !fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        *l1Head = head;
        *l2Head = slowPtr->next;
        slowPtr->next = NULL;
    }

public:
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode *temp = head, *l1, *l2;

        splitList(temp, &l1, &l2);

        return sortedMerge(sortList(l1), sortList(l2));
    }
};
