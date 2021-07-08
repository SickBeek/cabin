#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

class Solution {
	public:
		bool isValid(string str){
			stack<char> store;
			for (auto s: str){
				if (s=='(') store.push(')');
				else if (s=='[') store.push(']');
				else if (s=='{') store.push('}');
				
				else if (s==')'|| s==']' || s=='}'){
					if (store.empty() || store.top()!=s)
						return false;

					store.pop();
				}
			}
			return store.empty();
		}
};

int main (){
	Solution sol=Solution();

	if (sol.isValid("()")){
		cout<<"true"<<endl;
	}else {
		cout<<"false"<<endl;
	}


	return 0;
}
