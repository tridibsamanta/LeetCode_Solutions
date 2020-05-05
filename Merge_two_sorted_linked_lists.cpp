/**
 * Title   : Merge two sorted linked lists
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
 **/

// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(struct Node* a, struct Node* b);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;

    cin>>T;

    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;

        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}



// } Driver Code Ends



/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists

/*
// Recursive Approach

Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *result = NULL;

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data) {
        result = head1;
        result->next = sortedMerge(head1->next, head2);
    }
    else {
        result = head2;
        result->next = sortedMerge(head1, head2->next);
    }
    return result;
}
*/

// Iterative Approach

Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *temp1 = head1, *temp2 = head2, *result = NULL;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (temp1->data <= temp2->data) {
        result = temp1;
        temp1 = temp1->next;
    }
    else {
        result = temp2;
        temp2 = temp2->next;
    }

    Node *temp3 = result;

    while (temp1 != NULL && temp2 != NULL) {

        if (temp1->data <= temp2->data) {
            temp3->next = temp1;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        else {
            temp3->next = temp2;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
    }

    if (temp1 == NULL)
        temp3->next = temp2;
    else
        temp3->next = temp1;

    return result;
}
