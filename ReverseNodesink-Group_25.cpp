/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 25. Reverse Nodes in k-Group
~ Link      : https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *current = head;
        int count = 0;
        while (current != NULL && count != k) {
            ++count;
            current = current->next;
        }
        if (count == k) {
            ListNode *next = NULL, *prev = NULL; current = head;
            while (count) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                --count;
            }
            if (next != NULL)
                head->next = reverseKGroup(next, k);
            return prev;
        }
        return head;
    }
};
