public class Main {
	static public void main (String []args){
	}
}
class Solution {
	public ListNode reverseKGroup(ListNode head, int k){
		ListNode prev, cur, fast, tail, tmp, newHead;
		int count;

		count=k-1;
		cur=fast=tail=head;
		while (fast!=null && count>0){
			fast=fast.next;
			count--;
		}

		if (fast==null){  //total length < k
			return head;
		}

		newHead=fast;
		while (true){
			prev=null;
			count=k;
			tail=cur; //current head ---> after tail
			while (count>0){
				tmp=cur.next;
				cur.next=prev;
				prev=cur;
				cur=tmp;
				if (count>1 && fast!=null){ //fast denotes the kth node
					fast=fast.next; //fast forward
				}
				count--;
			}

			if (fast==null){ //rest<k
				tail.next=cur;
				return newHead;
			}
			tail.next=fast;
		}
		//return newHead;
	}
}

 public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
