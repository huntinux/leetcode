/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode p,q,r,n;

        p = head;
        q = p.next;
        while(p!=null)
        {
            while( q!= null && p.val == q.val)
                q = q.next;
            if(q != p.next)
            {
                r = p.next;
                p.next = q;
                //while(r<q)
                //{
                //    n = r.next;
                //    r = null;
                //    r = n;
                //}
            }
            p = q;
            if(p != null)
                q = p.next;
            else
                break;
        }
        return head;
        
    }
}
