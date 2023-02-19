/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 725. Split Linked List in Parts
~ Link      : https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head)
            return vector<ListNode*> (k, NULL);

        int nodeCount = 0;
        ListNode *curr = head;

        while (curr) {
            ++nodeCount;
            curr = curr -> next;
        }

        vector<ListNode*> res;

        curr = head;
        int groupCount = nodeCount / k, extra = nodeCount % k;

        for (int i = 1; i <= k; ++i) {
            ListNode *currHead = NULL;

            if (groupCount) {
                currHead = curr;

                for (int j = 1; j < groupCount; ++j)
                    curr = curr -> next;
            }

            if (extra) {
                if (!currHead)
                    currHead = curr;
                else
                    curr = curr -> next;

                --extra;
            }

            ListNode *tail = curr;

            if (curr -> next != NULL)
                curr = curr -> next;

            tail -> next = NULL;

            res.emplace_back(currHead);
        }

        return res;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(k)
