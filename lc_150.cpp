#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
	public:
		int eval_RPN(vector <string> &str){
			stack<int> store;
			int result, op1, op2;

			for (auto v: str){
				if (store.empty()){
					store.push(stoi(v));
				}else if (v=="+" ){
					op1=store.top();
					store.pop();
					op2=store.top();
					store.pop();
					store.push(op1+op2);
				}else if (v=="-"){
					op1=store.top();
					store.pop();
					op2=store.top();
					store.pop();
					store.push(op1-op2);
				}else if (v=="*"){
					op1=store.top();
					store.pop();
					op2=store.top();
					store.pop();
					store.push(op1*op2);
				}else if (v=="/"){
					op1=store.top();
					store.pop();
					op2=store.top();
					store.pop();
					store.push(int(op2/op1));
				}else {
					store.push(stoi(v));
				}
			}
			return store.top();
		}
};
int main (){
	vector<string> tokens={"4", "13", "5", "/", "+"};
	Solution sol=Solution();

	cout<<sol.eval_RPN(tokens)<<endl;
	return 0;
}
