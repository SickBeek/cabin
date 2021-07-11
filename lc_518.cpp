#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	public:
		int coinChange(int amount, vector<int>& coins){
			int i,j, n;

			n=coins.size();
			vector<int> dd(amount+1, 0);
			dd[0]=1;
			for (j=coins[i];j<=amount;j++){
				for (i=0;i<n;i++){
					dd[j]+=dd[j-coins[i]];
				}

				for (auto d: dd){
					cout<<d<<" ";
				}
				cout<<endl;
			}
			return dd[amount];
		}
};

int main (){
	Solution sol;
	vector<int> coins={1,2,5,4};
	int target=5;

	cout<<sol.coinChange(target, coins)<<endl;
	return 0;
}
