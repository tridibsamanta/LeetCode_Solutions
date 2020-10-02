/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 430. Flatten a Multilevel Doubly Linked List
~ Link      : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        Node *curr = head;

        while (curr) {

            if (curr -> child) {

                Node *next = curr -> next, *temp = curr -> child;

                curr -> next = temp;
                curr -> child = NULL;
                temp -> prev = curr;

                while (temp -> next)
                    temp = temp -> next;

                temp -> next = next;
                if (next)
                    next -> prev = temp;
            }

            curr = curr -> next;
        }

        return head;
    }
};
