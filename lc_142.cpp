#include <iostream>
#include <assert.h>
#include <stack>
#include <map>
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
		ListNode *find_cycle(ListNode *head){
			if (head->next==nullptr)
				return nullptr;

			ListNode *iter, *dummy;
			map<ListNode *, int> store;
			iter=nullptr;
			dummy=new ListNode();
			dummy->next=head;


			iter=head;
			while (iter!=nullptr){
				if (store.find(iter)==store.end()){
					store[iter]=1;
					iter=iter->next;
				} else {
					return iter;
				}
			}
			return nullptr;
		}
		
		ListNode* find_cycle_2pointers(ListNode *head){
			if (head==nullptr || head->next==nullptr)
				return nullptr;

			ListNode *slow, *fast;
			slow=fast=head;
			bool flag=false;

			while (fast!=nullptr && fast->next!=nullptr){
				slow=slow->next;
				fast=fast->next->next;
				if (slow==fast){
					flag=true;
					break;
				}
			}
			if (flag==false)
				return nullptr;
			else {
				slow=head;
				while (slow!=fast){
					slow=slow->next;
					fast=fast->next;
				}
				return slow;
			}
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

	for (int i=3;i>0;i--){
		add=new ListNode(i);
		add->next=lead;
		lead=add;
	}

	sol.find_cycle(lead);

	add=lead;
	while (add!=nullptr){
		cout<<add->val<<" ";
		add=add->next;
	}
	cout<<endl;

	return 0;
}
