#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	private:
		const string letterMap[10]={
			"",
			"",
			"abc",
			"def", //2
			"ghi",
			"jkl",
			"mno", //6
			"pqrs",
			"tuv",
			"xyz" //9
		};

	public:
		vector<string> result;
		string path;

		void backtracking(const string &digits, int index){
			if (index==digits.size()){
				result.push_back(path);
				return ;
			}

			int digit=digits[index] - '0';
			string letters=letterMap[digit];

			for (int i=0;i<letters.size();i++){
				path.push_back(letters[i]);
				backtracking(digits, index+1);
				path.pop_back();
			}
		}

		vector<string> letterCombination(string digits){
			if (digits.size()==0){
				return result;
			}

			//backtracking(digits, 0);
			combination(digits);
			return result;
		}

		void combination(const string &digits){
			if (path.size()==digits.size()){
				result.push_back(path);
				return ;
			}

			int digit=digits[path.size()] - '0';
			string letters=letterMap[digit];

			for (auto s:letters){
				path.push_back(s);
				combination(digits);
				path.pop_back();
			}
		}

};

int main(){
	string str="23";
	Solution sol;
	vector<string> res;

	res=sol.letterCombination(str);
	for(auto s: res){
		cout<<s<<endl;
	}
	return 0;
}
