/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2130. Maximum Twin Sum of a Linked List
~ Link      : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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
        if (!head || !head -> next)
            return head;

        ListNode *prev = NULL, *curr = head, *next = head;

        while (curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *prev = NULL, *slowPtr = head, *fastPtr = head;

        while (fastPtr && fastPtr -> next) {
            prev = slowPtr;
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }

        prev -> next = NULL;

        ListNode *newHead = reverseList(slowPtr);

        int maxTwinSum = 0;

        ListNode *curr = head;

        while (curr != NULL && newHead != NULL) {
            int currTwinSum = curr -> val + newHead -> val;
            maxTwinSum = max(maxTwinSum, currTwinSum);

            curr = curr -> next;
            newHead = newHead -> next;
        }

        return maxTwinSum;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
