#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	vector<int> path;
	int fewest;
	public:
		int coinChange_TLE(vector<int> &coins, int target){
			fewest=INT_MAX;
			combine(coins, target, 0);
			if (fewest==INT_MAX){
				return -1;
			}
			return fewest;
		}

		void combine(vector<int> &coins, int tar,unsigned int sum){
			if (tar==(int)sum){
				fewest=min(fewest, (int)path.size());
			}

			for (int i=0;i<coins.size();i++){
				if (sum+coins[i]>tar){
					continue;
				}
				path.push_back(coins[i]);
				combine(coins, tar,  sum+coins[i]);
				path.pop_back();
			}
		}

		int coinChange(vector<int>& coins, int amount){
			int i,j, n;

			n=coins.size();
			vector<int> dd(amount+1, 0);
			dd[0]=0;
			for (i=0;i<n;i++){
				for (j=1;j<=amount;j++){
					dd[j]=min(dd[j], dd[j-coins[i]]+1);
				}

				for (auto d: dd){
					cout<<d<<" ";
				}
				cout<<endl;
			}
			if (dd[amount]>amount)
				return -1;
			return dd[amount];
		}
};

int main (){
	Solution sol;
	vector<int> coins={1,2,5};
	int target=11;

	cout<<sol.coinChange(coins, target)<<endl;
	return 0;
}
