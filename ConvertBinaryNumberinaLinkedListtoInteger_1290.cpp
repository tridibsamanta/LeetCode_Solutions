/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1290. Convert Binary Number in a Linked List to Integer
~ Link      : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    // Approach 1
    int getDecimalValue(ListNode* head) {

        int result = head -> val;

        while (head -> next != NULL) {
            result = (result << 1) | head -> next -> val;
            head = head -> next;
        }

        return result;
    }

    // Approach 2.1
    /*
    int getDecimalValue(ListNode* head) {

        int result = head -> val;

        while (head -> next != NULL) {
            result = result * 2 + head -> next -> val;
            head = head -> next;
        }

        return result;
    }
    */

    // Approach 2.2
    /*
    int getDecimalValue(ListNode* head) {

        int result = 0;

        while (head != NULL) {
            result = result * 2 + head -> val;
            head = head -> next;
        }

        return result;
    }
    */
};

// T.C. - O(N)
// S.C. - O(1)
