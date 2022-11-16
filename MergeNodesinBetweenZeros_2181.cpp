/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2181. Merge Nodes in Between Zeros
~ Link      : https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy, *curr = head -> next;
        int sum = 0;

        while (curr != NULL) {
            if (curr -> val == 0) {
                prev -> next = new ListNode(sum);
                prev = prev -> next;
                sum = 0;
            }
            else {
                sum += curr -> val;
            }

            curr = curr -> next;
        }

        return dummy -> next;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
