/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
            return head;

        ListNode pre, cur, pos;
        pre = null;
        cur = head;
        while(cur != null)
        {
            pos = cur.next;
            cur.next = pre;
            pre = cur;
            cur = pos;
        }
        return pre;
    }
}
