#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

class Solution{
	public:
		int backpackMaxValue(vector<int> &w, vector<int> &v, int weight){
			int i,j, sum;
		}

		int backpackMaxValue(){
			vector<int> w={1,3,4};
			vector<int> v={15,20,30};
			int bagWeight=4;

			vector<int> dd(bagWeight+1, 0); //if weight[i]<0, INT_MIN
			for (int i=0;i<w.size();i++){
				for (int j=bagWeight;i>=weight[i];j--){
					dd[j]=max(dd[j], dd[j-weight[i]]+value[i]);
				}
			}
			return dd[bagWeight];
		}
};

int main(){
	return 0;
}
