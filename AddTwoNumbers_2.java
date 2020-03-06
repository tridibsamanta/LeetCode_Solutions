/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2. Add Two Numbers
~ Link      : https://leetcode.com/problems/add-two-numbers/
*/

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode curr = result;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int x, y;
            x = (l1 != null)?l1.val:0;
            y = (l2 != null)?l2.val:0;
            int sum = x + y + carry;
            curr.next = new ListNode(sum % 10);
            carry = sum / 10;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
            curr = curr.next;
        }
        if (carry > 0) {
            curr.next = new ListNode(1);
        }
        return result.next;
    }
}
