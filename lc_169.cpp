#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
	public:
		int majority_element(vector <int> &nums){
			stack<int> st;
			vector<int>::size_type ptr;

			for (auto s: nums){
				if (st.empty() || st.top()==s){
					st.push(s);
				}else {
					st.pop();
				}
			}
			return st.top();
		}
};

int main (){
	//vector<int> tokens={1,3,-1,-3,5,3,6,7};
	vector<int> tokens={1,-1};
	Solution sol=Solution();

	for (auto i: sol.max_sliding_window(tokens, 1))
		cout<<i<<",";
	cout<<endl;
	return 0;
}
