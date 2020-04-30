/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 206. Reverse Linked List
~ Link      : https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *next = NULL, *temp = NULL;
        while (head) {
            next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }
};
