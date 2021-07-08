#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode ():val(0), next(nullptr){}
	ListNode (int x):val(x), next(nullptr){}
	ListNode (int x, ListNode *next):val(0), next(next){}
	//~ListNode()
	void print(){
		ListNode *tmp=this;
		while (tmp!=nullptr){
			cout<<tmp->val<<" ";
			tmp=tmp->next;
		}
		cout<<endl;
	}
};


class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode * i1, *i2, *head, *tail, *remain;
       int incre, sum;

       incre=sum=0;
       i1=l1; i2=l2;
       head=new ListNode(-1);
	   tail=head;

       while (i1!=nullptr && i2 !=nullptr){
           sum=i1->val+ i2->val+ incre;
           tail->next=new ListNode(sum%10);
		   tail=tail->next;
           incre=sum/10;
           i1=i1->next; i2=i2->next;
       }

       remain = (i1==nullptr)?i2:i1;

       while (remain !=nullptr){
		   sum=remain->val+incre;
           tail->next=new ListNode(sum%10);
           tail=tail->next;
           incre=sum/10;
           remain=remain->next;
       }

	   if (incre){
		   tail->next=new ListNode (incre);
		   //tail=tail->next;
	   }
       return head->next;
   }

    bool isPalindrome(int num){
        int save, sum;
        save=num;
        sum=0;

        while (num!=0){
            sum*=10;
            sum+=num%10;
            num/=10;
        }
        return sum==save;
    }

    int superpalindromesInRange(string left, string right) {
        int num1, num2, i ,count, root;
        num1=num2=count=0;

		///*
        for (auto s: left){
            num1+=s-'0';
            num1*=10;
        }
        num1/=10;

        for (auto s: right){
            num2+=s-'0';
            num2*=10;
        }
        num2/=10;
		//*/

		//num1=stoi(left);
		//num2=stoi(right);

        for (i=num1;i<=num2;i++){
            if (isPalindrome(i)){
				root=sqrt(i);
				if (root*root==i && isPalindrome(root))
					count++;
			}
        }
        return count;
    }
};

int main (){
	Solution sol=Solution();
	ListNode *add, *num1, *num2, *result;
	num1=num2=result=nullptr;

//	vector<int> l1={3,4,2};
//	vector<int> l2={4,6,5};

	vector<int> l1(7,9);
	vector<int> l2(4,9);

	for (auto i: l1){
		add=new ListNode(i);
		add->next=num1;
		num1=add;
	}

	for (auto i: l2){
		add=new ListNode(i);
		add->next=num2;
		num2=add;
	}

	num1->print();
	num2->print();

	result=sol.addTwoNumbers(num1, num2);
	result->print();
	
	cout<<sol.superpalindromesInRange("4", "1000")<<endl;
	return 0;
}
