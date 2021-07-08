#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Solution{
	public:
		static bool cmp(vector<int> a, vector<int> b){
			if (a[0]==b[0]) return a[1]<b[1];
			return a[0]>b[0];
		}

		vector<vector<int>> reconstructQueue(vector<vector<int>> & people){
			sort(people.begin(), people.end(), cmp);
			vector<vector<int>> que;
			for (int i=0;i<people.size();i++){
				int pos=people[i][1];
				que.insert(que.begin() + pos, people[i]);
			}
			return que;
		}

		vector<vector<int>> reconstructQueue_list(vector<vector<int>> & people){
			sort(people.begin(), people.end(), cmp);
			list<vector<int>> que;
			for (int i=0;i<people.size();i++){
				int pos=people[i][1];
				//list<vector<int>>::iterator it=que.begin();
				auto it=que.begin();
				while (pos--){
					it++;
				}
				que.insert(it, people[i]);
			}
			return vector<vector<int>>(que.begin(), que.end());
		}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
			sort(people.begin(),people.end(),[](auto& p, auto& q) {
				return p[0] == q[0] ? p[1] > q[1] : p[0] < q[0];
			});
			
			int n(people.size());
			int bit[n+1];
			memset(bit,0,sizeof(bit));
			auto update = [&bit,&n](int i, int x) {
				for (;i <= n; i += (i&-i)) bit[i] += x;
			};
			auto get = [&bit](int i) {
				int res(0);
				for (;i; i-=(i&-i)) res += bit[i];
				return res;
			};
			for (int i(0); i < n; ++i) update(i+1,1);
			vector<vector<int>> res(n);
			for (auto& p : people) {
				int l(0), r(n-1);
				while (l < r) {
					int m = l+(r-l)/2;
					if (p[1] < get(m+1)) r = m;
					else l = m+1;
				}
				res[l] = p;
				update(l+1,-1);
				
			}
			
			return res;
		}
};

int main (){
	return 0;
}
