/**

 * Definition for singly-linked list.

 * public class ListNode {

 *     int val;

 *     ListNode next;

 *     ListNode(int x) { val = x; }

 * }

*/

public class Solution {

    public void deleteNode(ListNode node) {
        if (node == null || node.next == null)
            return;

        ListNode cur, pre;
        pre = null;
        cur = node;

        while(cur.next != null)
        {
            cur.val = cur.next.val;
            pre = cur;
            cur = cur.next;
        }
        pre.next = null;
        cur = null;
    }

}
