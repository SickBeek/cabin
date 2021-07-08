#include <iostream>
#include <assert.h>
#include <stack>
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
		bool isPalindrome_force(ListNode * head){
			ListNode *iter, *dummy, *fast;
			int len, mid;
			stack<int> store=stack<int>();
			dummy=new ListNode();

			len=mid=-1;
			dummy->next=head;
			iter=dummy;

			while (iter!=nullptr){
				iter=iter->next;
				len++;
			}

			mid=len/2;
			fast=dummy;
			while (mid-- && fast!=nullptr){
				fast=fast->next;
				store.push(fast->val);
			}

			if (len%2){
				fast=fast->next->next;
			}else {
				fast=fast->next;
			}

			while (fast->next!=nullptr){
				if (store.top()!=fast->val){
					return false;
				}
				fast=fast->next;
				store.pop();
			}
			
			if (fast->val==store.top()){
				return true;
			}
			return false;
		}

		bool isPalindrome_2pointers(ListNode *head){
			if (head==nullptr)
				return false;

			if (head->next==nullptr)
				return true;

			ListNode *slow, *fast, *latter, *cur;
			slow=head;
			fast=head->next;
			while (fast!=nullptr && fast->next!=nullptr){
				slow=slow->next;
				fast=fast->next->next;

			}
			slow=slow->next;   //slow points to the right part
			cur=slow;         //fast=current node
			latter=slow->next;   //latter=next node
			fast->next=nullptr;

			while (latter!=nullptr){   //reverse right part
				tmp=latter->next;
				latter->next=fast;

				fast=latter;
				latter=tmp;
			}
			
			latter=head;
			if (latter->val!=fast->val)  //when slow==fast at first
				return false;

			while (fast!=slow){      //fast=last node
				latter=latter->next;
				fast=fast->next;
				if (latter->val!=fast->val){
					return false;
				}
			}
			return true;
		}
};

int main (){
	Solution sol=Solution();
	ListNode *lead, *add;
	lead=nullptr;

	for (int i=1;i<3;i++){
		add=new ListNode(i);
		add->next=lead;
		lead=add;
	}

	for (int i=2;i>0;i--){
		add=new ListNode(1);
		add->next=lead;
		lead=add;
	}

	if (sol.isPalindrome_2pointers(lead))
		cout<<"true"<<endl;

	add=lead;
	while (add!=nullptr){
		cout<<add->val<<" ";
		add=add->next;
	}
	cout<<endl;

	return 0;
}
