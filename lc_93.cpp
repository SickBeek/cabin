#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
	//private:
	vector<string> result;

	void combine(string& s, int idx, int comma_count){
		if (comma_count==3){
			if (ip_valid(s, idx, s.size()-1)){  //the fourth/last segment
				result.push_back(s);
			}
			return;
		}

		for (int i=idx;i<s.size();i++){
			if (ip_valid(s, idx, i)){  //current segment
				s.insert(s.begin()+i+1, '.');
				combine(s, i+2, comma_count+1); //i+1 is comma's position
				s.erase(s.begin()+i+1);
			}else {
				break;
			}
		}
	}

		bool ip_valid(const string& s, int start, int end){
			if (start>end || end-start>2){
				return false;
			}

			if (s[start]=='0' && start!=end){ //0-leading
				return false;
			}

			int num=0;
			for (int i=start;i<=end;i++){
				if (s[i]>'9' || s[i]<'0'){
					return false;
				}
				num*=10; num+=s[i]-'0';
				//num=num*10+s[i]-'0';
				if (num>255)
					return false;
			}
			return true;
		}

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
