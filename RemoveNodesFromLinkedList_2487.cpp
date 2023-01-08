/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2487. Remove Nodes From Linked List
~ Link      : https://leetcode.com/problems/remove-nodes-from-linked-list/
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

/* Approach 1: Using Stack */
/*
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *curr = head;
        stack<ListNode*> stk;

        while (curr) {
            stk.push(curr);
            curr = curr -> next;
        }

        ListNode *newHead = NULL;
        int rightMaxVal = INT_MIN;

        while (!stk.empty()) {
            curr = stk.top();
            stk.pop();

            if (curr -> val >= rightMaxVal) {
                curr -> next = newHead;
                newHead = curr;
                rightMaxVal = curr -> val;
            }
        }

        return newHead;
    }
};
*/
// Time Complexity - O(n)
// Space Complexity - O(n)

/* Approach 2: Using Recursion */

class Solution {
public:
    ListNode* removeNodes(ListNode *head) {
        if (!head -> next)
            return head;

        ListNode *validNode = removeNodes(head -> next);

        if (head -> val >= validNode -> val) {
            head -> next = validNode;
            validNode = head;
        }

        return validNode;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
