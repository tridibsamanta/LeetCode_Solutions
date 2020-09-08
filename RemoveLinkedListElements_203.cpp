/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 203. Remove Linked List Elements
~ Link      : https://leetcode.com/problems/remove-linked-list-elements/
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

// Approach 1 : (Iterative)
/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *headRef = NULL, *prev = NULL, *curr = head;

        while (curr != NULL) {

            if (curr -> val == val) {

                ListNode *temp = curr;
                curr = curr -> next;

                if (prev != NULL)
                    prev -> next = curr;

                delete temp;

            }
            else {

                if (headRef == NULL)
                    headRef = curr;

                prev = curr;
                curr = curr -> next;
            }
        }

        return headRef;
    }
};
*/

// Approach 2 : (Recursive)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if (!head)
            return NULL;

        ListNode *next = removeElements(head -> next, val);

        if (head -> val == val)
            return next;

        head -> next = next;
        return head;
    }
};

