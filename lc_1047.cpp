#include <iostream>
#include <assert.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
	public:
		string remove_duplicates_2pointers(string str){
			if (str.size()<2)
				return str;

			string::size_type slow, fast, end_pos;
			bool flag;

			flag=false;
			end_pos=str.size()-1;
			slow=fast=1;

			while (true){
				slow=fast=1;
				flag=false;

				for (;fast<=end_pos;fast++){
					if (str[fast]!=str[fast-1]){
						str[slow++]=str[fast];
					}else{
						flag=true;
						slow--;
					}
				}
				if (flag){
					end_pos=slow;
				}else{
					str.resize(end_pos-1);
					break;
				}
			}
			return str;
		}

		string remove_duplicates_stack1(string str){
			if (str.size()<2)
				return str;

			string::size_type slow, fast, end_pos;
			stack<string::value_type> store;

			end_pos=str.size()-1;
			slow=fast=1;
			store.push(str[0]);

			for (;fast<=end_pos;fast++){
				if (!store.empty()){
					if (str[fast]!=store.top()){
						str[slow++]=str[fast];
					}else{
						store.pop();
						slow--;
					}
				}else{
					store.push(str[fast]);
					slow++;
				}
			}
			str.resize(slow);

			return str;
		}


		string remove_duplicates_stack_reverse(string str){
			if (str.size()<2)
				return str;
			
			stack<char> store;
			string result="";
			
			for (auto s: str){
				if (store.empty() || store.top()!=s){
					store.push(s);
				}
				//}else if (store.top()==s){
				else{
					store.pop();
				}
			}

			while (!store.empty()){
				result+=store.top();
				store.pop();
			}
			reverse(result.begin(), result.end());
			return result;

		}

		string remove_duplicates_stack_string(string str){
			if (str.size()<2)
				return str;

			string::size_type ptr;
			string result="";

			for (auto s :str){
				if (result.empty() || result.back()!=s){
					result.push_back(s);
				}else {
					result.pop_back();
				}
			}
			return result;
		}
};

int main (){
	Solution sol=Solution();
	string target="bbbbb";
	cout<<sol.remove_duplicates_stack1(target)<<endl;
	
	return 0;
}
