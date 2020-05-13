/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 234. Palindrome Linked List
~ Link      : https://leetcode.com/problems/palindrome-linked-list/
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
    bool checkPalindrome(ListNode *list1, ListNode *list2) {
    ListNode *temp1 = list1, *temp2 = list2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val == temp2->val) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return false;
    }
    return true;
    }

    void reverseList(ListNode **head) {
    ListNode *prev = NULL, *current = *head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
        return true;

        ListNode *slowPtr = head, *prev_slowPtr = head, *fastPtr = head;

        while (fastPtr != NULL && fastPtr->next != NULL) {
            fastPtr = fastPtr->next->next;
            prev_slowPtr = slowPtr;
            slowPtr = slowPtr->next;
        }

        ListNode *middleNode = NULL, *head2 = NULL;

        if (fastPtr != NULL) {
            middleNode = slowPtr;
            slowPtr = slowPtr->next;
        }

        head2 = slowPtr;
        prev_slowPtr->next = NULL;

        reverseList(&head2);

        bool check;
        check = checkPalindrome(head, head2);

        reverseList(&head2);

        if (middleNode != NULL) {
            prev_slowPtr->next = middleNode;
            middleNode->next = head2;
        }
        else
            prev_slowPtr->next = head2;

        return check;
    }
};
