/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 82. Remove Duplicates from Sorted List II
~ Link      : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;

        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *prev = dummy, *curr = head;

        while (curr != NULL) {
            // current node value is duplicate
            if (curr -> next != NULL && curr -> val == curr -> next -> val) {

                ListNode *temp = curr;

                // skip all nodes equal to current node value
                while (temp != NULL && temp -> val == curr -> val) {
                    temp = temp -> next;
                }

                curr = temp;
            }
            // current node value is distinct
            else {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
        }

        prev -> next = NULL;

        return dummy -> next;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
