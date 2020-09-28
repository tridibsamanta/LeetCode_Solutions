/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 23. Merge k Sorted Lists
~ Link      : https://leetcode.com/problems/merge-k-sorted-lists/
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

    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i])
                minHeap.push(lists[i]);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (!minHeap.empty()) {

            ListNode *top = minHeap.top();
            minHeap.pop();

            if (top -> next)
                minHeap.push(top -> next);

            tail -> next = top;
            tail = tail -> next;
        }

        return dummy -> next;
    }
};
