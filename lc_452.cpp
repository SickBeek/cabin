#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Solution{
	public:
		static bool cmp(vector<int> &a, vector<int> &b){
			if (a[0]==b[0]) return a[1]<b[1];
			return a[0]<b[0];
		}

		int arrows_min(vector<vector<int>> &points){
			sort(points.begin(), points.end(), cmp);

			int result, cur_border;
			result=1;
			cur_border=points[0][1];
			for (int i=1;i<points.size();i++){
				if (points[i][0]> points[i-1][1]){
					cur_border=points[i][1];
					result++;
				}else {
					cur_border=min(points[i][1], points[i-1][1]);
				}
			}
			return result;
		}

		int erase_overlap(vector<vector<int>> &in){
			if (in.size()==1) return 0;

			sort(in.begin(), in.end(), cmp);

			int count, left, i, n;

			count=1;
			n=in.size();
			left=in[n-1][0];
			for (i=n-2;i>=0;i--){
				if (left > in[i][1]){
					left=in[i][0];
					count++; //non-overlapping number
				}
			}
			return n-count;
		}

};

int main (){
	Solution sol;
	vector<vector<int>> ballons={{10,16}, {2,8}, {1,6},{7,12} };

	sol.arrows_min(ballons);
	return 0;
}
