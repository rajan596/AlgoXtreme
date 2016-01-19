/* C++ Code  */
class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;

            ListNode* head = NULL;    // head of the list to return

            // find first element (can use dummy node to put this part inside of the loop)
            if(l1->val < l2->val) { 
                head = l1; 
                l1 = l1->next; 
            } else { 
                head = l2; 
                l2 = l2->next; 
            }

            ListNode* p = head;     // pointer to form new list

            while(l1 && l2){
                if(l1->val < l2->val) { 
                    p->next = l1; 
                    l1 = l1->next; 
                } else { 
                    p->next = l2; 
                    l2 = l2->next; 
                }
                p = p->next;
            }

            // add the rest of the tail, done!
            if (l1) { 
                p->next=l1;
            } else {
                p->next=l2;
            }

            return head;
            }
};

/*  ANOTHER METHOD */

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
	public ListNode mergeTwoLists(ListNode a, ListNode b) {
	    ListNode temp;
	    if(a==null) return b;
	    if(b==null) return a;
	    
	    ListNode first,t1,t2,t3;
	    
	    if(a.val>b.val) {
	        first=b;
	        t2=b;
	        t1=a; 
	    }
	    else{
	       first=a;  
	       t2=a;
	       t1=b;
	    } 
	    
	    while(t1!=null && t2!=null) {
	        if(t2.next==null) {
	            t2.next=t1;
	            break;
	        }
	        else if(t2.next.val<t1.val) {
	            t2=t2.next;
	        }else {
	            t3=t2.next;
	            t2.next=t1;
	            t2=t2.next;
	            t1=t1.next;
	            t2.next=t3;
	        }
	    }
	    
	    return first;
	}
}
