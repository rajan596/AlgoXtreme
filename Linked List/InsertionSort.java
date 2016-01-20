/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
	public ListNode insertionSortList(ListNode a) {
	    if(a==null || a.next==null) return a;
	    ListNode dummy=new ListNode(-1);
	    dummy.next=a;
	    a=dummy;
	    
	    ListNode p=a,t=a,curr=null;
	    
	    while(t!=null && t.next!=null) {
	        p=a;
	        while(p!=t && p.next.val<=t.next.val) {
	            p=p.next;
	        }
	        if(p!=t) {
	            curr=t.next;
	            t.next=t.next.next;
	            curr.next=p.next;
	            p.next=curr;
	        }else {
	            t=t.next;
	        }
	    }
	    
	    return a.next;
	}
}
