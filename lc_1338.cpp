#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

class Solution{
	public:
		static bool cmp_error(pair<int, int> &a,pair<int, int> &b){
			return a.second> b.second;
		}

		static bool cmp(int &a, int &b){
			return a>b;
		}

		int minSetSize_error(vector<int> &arr){
			map<int, int> umap;
			int i, count, n, half, sum;

			half=(n-1)/2 + 1;
			n=arr.size();
			for (i=0;i<n;i++){
				if (umap.find(arr[i])==umap.end()){
					umap.insert({arr[i], 1});
				}else {
					umap[arr[i]]++;
				}
			}

			sort(umap.begin(), umap.end(), cmp);
			sum=count=0;
			for (auto m: umap){
				sum+=m.second;
				count++;
				if (sum>=half){
					return count;
				}
			}
			return count;
		}

		int minSetSize_umap2vector(vector<int> &arr){
			unordered_map<int, int> umap;
			vector<int> freq;
			int i, count, n, half, sum;

			for (auto a:arr) umap[a]++;
			for (auto [_, f]: umap){
				freq.push_back(f);
			}
			sort(freq.begin(), freq.end(), cmp);

			n=arr.size();
			half=(n-1)/2 + 1; //ceil divide
			count=sum=0;
			for (auto f: freq){
				sum+=f;
				count++;
				if (sum>=half){
					return count;
				}
			}
			return count;
		}
};

int main (){
	Solution sol;
	vector<int> arr={1,2,3,4,5,6,7,7,7};
	sol.minSetSize(arr);
	return 0;
}
