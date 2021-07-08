#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		void get_next(vector<int> &next, string& s){
			int j, i;

			j=-1;
			next[0]=-1;
			for (i=1;i<s.size();i++){
				while (j>0 && s[i]!=s[j+1]){  // equal
					j=next[j];
				}
				if (s[i]==s[j+1]){  //not equal
					j++;
				}
				next[i]=j;
			}
		}

		int kmp(string &str, string &mode){
			vector<int> next(mode.size());
			int i,j;

			get_next(next, mode);
			i=0; j=-1;
			next[0]=j;
			for (;i<str.size();i++){
				while (j>=0 && str[i]!=mode[j+1]){
					j=next[j];
				}
				if (str[i]==mode[j+1]){
					j++;
				}
				if (j==mode.size()-1) {//j+1 hits the end
					return (i-mode.size()+1);
				}
			}
			return -1;
		}
};

int main(){
	Solution sol;
	string needle="abaababaab";
	string haystack="absdmabbaafasd";
	vector<int> next(needle.size());

	sol.get_next(next, needle);
	for (auto s : next)
		cout<<s<<" ";
	cout<<endl;
	cout<<"Found needle in: "<<sol.kmp(haystack, needle)<<endl;
	return 0;
}

