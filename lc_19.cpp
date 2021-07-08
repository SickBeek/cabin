#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode ():val(0), next(nullptr){}
	ListNode (int x):val(x), next(nullptr){}
	ListNode (int x, ListNode *next):val(0), next(next){}
	//~ListNode()
};


class Solution {
	public:
		ListNode *remove_Nth_reverse(ListNode *head, int n){
			ListNode *p=head;
			int len=0, index=0;

			while (p!=nullptr){
				len++;
				p=p->next;
			}
			if (len==n)
				return head->next;
			else
				index=len-n-1;

			p=head;
			for (;index>0;index--){
				p=p->next;
			}
			ListNode *d=p->next;
			p->next=d->next;
			delete d;

			return head;
		}

		ListNode *remove_Nth_reverse_2pointers(ListNode *head, int n){
			ListNode *slow, *fast;
			int i=0;
			slow=fast=head;

			if (head==nullptr)
				return head;

			while (n-- &&fast!=nullptr){
				fast=fast->next;
			}

			while (fast!=nullptr){
				slow=slow->next;
				fast=fast->next;
			}
			ListNode *tmp=slow->next;
			slow->next=tmp->next;
			delete tmp;

			return head;
		}
};

int main (){
	Solution sol=Solution();
	ListNode *lead, *add;
	lead=new ListNode(11);

	for (int i=1;i>0;i--){
		add=new ListNode(i);
		add->next=lead;
		lead=add;
	}

	//add=sol.remove_Nth_reverse(lead, 1);
	add=sol.remove_Nth_reverse_2pointers(lead, 3);

	while (add!=nullptr){
		cout<<add->val<<" ";
		add=add->next;
	}
	cout<<endl;

	return 0;
}
