/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 445. Add Two Numbers II
~ Link      : https://leetcode.com/problems/add-two-numbers-ii/
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

// ***** Approach 1 (Iterative) *****

class Solution {
private:
    ListNode* insertNode(ListNode *head, int data) {
        ListNode *temp = new ListNode(data);
        temp -> next = head;
        return temp;
    }

    int getListSize(ListNode *head) {
        int size = 0;
        while (head) {
            ++size;
            head = head -> next;
        }
        return size;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        int len1 = getListSize(l1);
        int len2 = getListSize(l2);

        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;

        while (len1 > 0 && len2 > 0) {
            int sum = 0;
            if (len1 >= len2) {
                sum = curr1 -> val;
                curr1 = curr1 -> next;
                --len1;
            }
            if (len2 > len1) {
                sum += curr2 -> val;
                curr2 = curr2 -> next;
                --len2;
            }
            res = insertNode(res, sum);
        }

        curr1 = res, res = NULL;
        int carry = 0;

        while (curr1) {
            curr1 -> val += carry;
            carry = curr1 -> val / 10;
            res = insertNode(res, curr1 -> val % 10);
            curr2 = curr1;
            curr1 = curr1 -> next;
            delete curr2;
        }

        if (carry)
            res = insertNode(res, 1);

        return res;
    }
};

// ***** Approach 2 (Using Stack) *****
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;

        stack <int> s1, s2;

        ListNode *temp = l1;
        while (temp) {
            s1.push(temp -> val);
            temp = temp -> next;
        }

        temp = l2;
        while (temp) {
            s2.push(temp -> val);
            temp = temp -> next;
        }

        ListNode *res = NULL;
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {

            int sum = 0;

            if (!s1.empty()) {
                sum = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;

            ListNode *newNode = new ListNode(sum % 10);
            newNode -> next = res;
            res = newNode;
            carry = sum / 10;
        }

        if (carry) {
            ListNode *newNode = new ListNode(1);
            newNode -> next = res;
            res = newNode;
        }

        return res;
    }
};
*/
