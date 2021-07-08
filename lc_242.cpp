#include <iostream>
#include <assert.h>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
//using std::cout;


class Solution {
	public:
		bool isAnagram(string s, string t){
			int rec[26]={0};
			string::size_type i=0;

			for (;i<s.size();i++){
				rec[s[i]-'a']++;
			}

			for (i=0;i<t.size();i++){
				rec[t[i]-'a']--;
			}

			for (i=0;i<26;i++){
				if (rec[i]!=0)
					return false;
			}
			return true;
		}

		bool isAnagram_map(string s, string t){
			return true;
		}
};

int main (){
	Solution sol=Solution();
	string s="anagram", t="naarma";

	cout<<sol.isAnagram(s, t)<<endl;
	return 0;
}
