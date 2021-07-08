#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode ():val(0), next(nullptr){}
	ListNode (int x):val(x), next(nullptr){}
	//ListNode (ListNode* next):val(0), next(next){}
	ListNode (int x, ListNode *next):val(0), next(next){}
	//~ListNode()
};


class Solution {
	public:
		ListNode * reverse_list(ListNode *head){
			ListNode *prev, *curr, *next;
			prev=next=nullptr;
			curr=head;

			while (curr!=nullptr){
				next=curr->next;
				curr->next=prev;
				prev=curr;
				curr=next;
			}
			return prev;
		}

		ListNode *reverse(ListNode *prev, ListNode* cur){
			if (cur==nullptr)
				return prev;

			ListNode *next=cur->next;
			cur->next=prev;
			//prev=cur;
			//cur=next;
			return reverse(cur, next);
		}

		ListNode * reverse_list_recursive(ListNode *head){
			return reverse(nullptr, head);
		}

};

int main (){
	Solution sol=Solution();
	ListNode *lead, *add;
	lead=new ListNode(11);

	for (int i=10;i>0;i--){
		add=new ListNode(i);
		add->next=lead;
		lead=add;
	}

	add=sol.reverse_list(lead);
	//sol.reverse_list(lead);
	//add=lead;

	while (add!=nullptr){
		cout<<add->val<<" ";
		add=add->next;
	}
	cout<<endl;

	return 0;
}
