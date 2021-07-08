#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	public:
		int stock_with_fees(vector<int> &prices, int fee){
			int result, min_price, i, n;

			result=i=0;
			n=prices.size();
			min_price=prices[0];
			for (i=1;i<n;i++){
				min_price=min(prices[i], min_price);

				if (prices[i] >= min_price && prices[i]<=min_price + fee){
					continue;
				}

				if (prices[i] > min_price + fee){
					result+=prices[i] - min_price -fee;
					min_price=prices[i] -fee;
				}
			}
			return result;
		}
};

int main (){
	return 0;
}
