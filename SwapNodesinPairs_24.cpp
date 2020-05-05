/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 24. Swap Nodes in Pairs
~ Link      : https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp;
        temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};
