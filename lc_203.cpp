#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode ():val(0), next(nullptr){}
	ListNode (int x):val(x), next(nullptr){}
	ListNode (ListNode* next):val(0), next(next){}
	ListNode (int x, ListNode *next):val(0), next(next){}
	//~ListNode()
};


class Solution {
	public:
		ListNode* remove_elements_error(ListNode *head, int val){
			ListNode *temp=head, *p=nullptr;
			if (head==nullptr)
				return head;

			if (head->val==val){
				p=head->next;
				head->next=p->next;
				delete p;
			}

			while (temp->next!=nullptr){
				if (temp->next->val==val){
					p=temp->next;
					temp->next=p->next;
					delete p;
				}else{
				temp=temp->next;
				}
				if (temp==nullptr){
					break;
				}
			}
			return head;
		}
	
		ListNode* remove_elements(ListNode *head, int val){
			ListNode *temp,*p;

			while (head!=nullptr&&head->val==val){
				temp=head;
				head=head->next;
				delete temp;
			}

			temp=head;
			while (temp!=nullptr &&temp->next!=nullptr){
				if (temp->next->val==val){
					p=temp->next;
					temp->next=p->next;
					delete p;
				}else{
					temp=temp->next;
				}
			}
			return head;
		}

		ListNode * remove_elements_dummy(ListNode *head, int val){
			ListNode* dummy=new ListNode(head);
			ListNode *temp, *p;
			temp=dummy;

			while (temp!=nullptr && temp->next!=nullptr){
				if (temp->next->val==val){
					p=temp->next;
					temp->next=p->next;
					delete p;
				} else{
					temp=temp->next;
				}
			}
			return temp->next;
		}
};

int main (){
	Solution sol =Solution();
	int target=4;
	ListNode *head=new ListNode(target);

	for (int i=20;i>0;i--){
		ListNode *temp=new ListNode(i);
		if (i%target==0){
			temp->val=target;
		}
		temp->next=head;
		head=temp;
	}
	//head->val=target;

	sol.remove_elements(head, target);
	ListNode *temp=head;

	while (temp!=nullptr){
		cout<<temp->val<<" ";
		temp=temp->next;
	}

	return 0;
}


/*
	ListNode* remove_elements(ListNode *head, int val){
		ListNode* dummy=new ListNode(head);
		ListNode *temp, *p;
		temp=dummy;

		while (temp!=nullptr && temp.next!=nullptr){
			if (temp.next.val==val){
				p=temp.next;
				temp.next=p.next;
				delete p;
			} else{
				temp=temp.next;
			}
		}
		return temp.next;
	}
 */
