#include <iostream>
#include <assert.h>
#include <stack>
#include <map>
using namespace std;

class Solution {
	public:
		string reverse_2k(string s, int k){
			int i, len;
			len=s.size();

			for (i=0;i<len;i+=2*k){
				if (n-i<=k){
					reverse (s.begin()+i, s.end());
				}else {
					reverse(s.begin()+i, s.begin()+i+k);
				}
			}
			return s;
		}

		string replace_space(string s){
			int count, i, size, new_size;
			count=0;
			size=s.size()

			for (i=0;i<size;i++){
				if (s[i]==' '){
					count++;
				}
			}
			
			s.resize(size+count*2);
			new_size=s.size();

			for (i=new_size-1, j=size-1;j<i;i--, j--){
				if (s[j]!=' '){
					s[i]=s[j];
				}else {
					s[i--]='0';
					s[i--]='2';
					s[i]='%';
				}
			}
			return s;
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
