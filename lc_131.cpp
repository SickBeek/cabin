#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
	vector<vector<string>> result;
	vector<string> path;

	public:
		vector<vector<string>> partition(string s){
			combine(s, 0);
			return result;
		}

		void combine(const string &s, int index){
			if (index> s.size()){
				result.push_back(path);
				return ;
			}

			for (int i=index;i<s.size();i++){
				////cout<<s.substr(index, i-index+1)<<endl;
				if (isPalindrome(s, index, i)){
					string str=s.substr(index, i-index+1);
					path.push_back(str);
				}else {
					continue;
				}

				combine(s, i+1);
				path.pop_back();
			}
		}

		bool isPalindrome(const string &s, int start, int end){
			int i,j;

			i=start;j=end;
			while (i<j){
				if (s[i]!=s[j])
					return false;
				i++; j--;
			}
			return true;
		}
};

int main (){
	Solution sol;
	string str="aab";
	vector<vector<string>> result;
	result=sol.partition(str);

	for (auto r: result){
		for (auto s: r){
			cout<<s<<",";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;

}
