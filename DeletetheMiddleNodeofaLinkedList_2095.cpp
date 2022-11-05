/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2095. Delete the Middle Node of a Linked List
~ Link      : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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
    ListNode* deleteMiddle(ListNode* head) {
        // list contains 1 node
        if (!head -> next)
            return NULL;

        // list contains >= 2 nodes
        ListNode *slowPtr = head, *fastPtr = head -> next -> next;

        while (fastPtr && fastPtr -> next) {
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }

        // slowPtr now points just before the node to be deleted
        slowPtr -> next = slowPtr -> next -> next;

        return head;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
