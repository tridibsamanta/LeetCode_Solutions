/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 138. Copy List with Random Pointer
~ Link      : https://leetcode.com/problems/copy-list-with-random-pointer/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;

        Node *curr = head;

        // creating brand new nodes and connecting it just
        // after the current node in the given list
        while (curr) {
            Node *copyNode = new Node(curr -> val);
            copyNode -> next = curr -> next;
            curr -> next = copyNode;
            curr = curr -> next -> next;
        }

        curr = head;

        // setting the random pointers of the newly created nodes
        while (curr) {
            curr -> next -> random = ((curr -> random == NULL) ? NULL : curr -> random -> next);

            curr = curr -> next -> next;
        }

        Node *newHead = head -> next, *nextNode;
        curr = head;

        // restoring the given list and the deep copy list
        while (curr) {
            nextNode = curr -> next;
            curr -> next = nextNode -> next;
            curr = curr -> next;

            if (curr)
                nextNode -> next = curr -> next;
        }

        return newHead;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
