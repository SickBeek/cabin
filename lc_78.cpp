#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{

	public:
		vector<string> restoreIP(string s){
			if (s.size()>12) return result;
			combine(s, 0, 0);
			return result;
		}
};

int main(){
	Solution sol;
	string str="25525511135";
	vector<string> res;

	res=sol.restoreIP(str);
	for (auto r: res){
		cout<<r<<" ";
	}
	cout<<endl;
	return 0;
}
