#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		int numDecodings(string s){
			if (!s.empty()){
				return decoding(0, s);
			}
			return 0;
		}

		int decoding(int idx, string& s){

			if (idx==s.size())
				return 1;

			if (s[idx]=='0')
				return 0;

			int res=decoding(idx+1, s);
			if (idx<n-1 &&(s[idx]=='1' || (s[idx]=='2' && s[idx+1]<'7'))){
				res+=decoding(idx+1, s);
			}
			return res;
		}

		int numDecodings_dp(string s){
			int n, i;
			vector<int> dd(n+1);

			n=s.size();
			dd[n]=1;
			for (i=n-1;i>=0;i--){
				if (s[i]=='0')
					dd[i]=0;
				else {
					dd[i]=dd[i+1];
					if (idx<n-1 &&(s[idx]=='1' || (s[idx]=='2' && s[idx+1]<'7'))){
						dd[i]+=dd[i+2];
					}
				}
			}
			if (!s.empty()) return dd[0];
			return 0;
		}
};

int main (){
	return 0;
}
