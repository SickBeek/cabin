#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
	public:
		int circuit_gas_brute(vector<int> &gas, vector<int> &cost){
			int tank, j, n;
			n=gas.size();
			for (int i=0;i<n;i++){
				tank=0;
				j=i;
				while (true){
					tank=gas[j]-cost[j];
					if (tank<0){
						break;
					}
					j=(j+1)%n;
					if (j==i){
						return j;
					}
				}
			}
			return -1;
		}

		int circut_gas_segment(vector<int> &gas, vector<int> &cost){
			int i,j,n,sum, mini, tank;

			mini=gas[0]-cost[0];
			tank=0;
			n=gas.size();
			for (i=0;i<n;i++){
				tank+=gas[i]-cost[i];
				mini=min(tank, min);
			}

			if (tank<0) return -1; //case 1: gas is less than cost in total
			if (mini>=0) return 0; //case 2: gas remained each travel

			for (i=n-1;i>=0;i--){ //case 3: mini is less than 0
				mini+=gas[i]-cost[i];
				if (mini>=0)
					return i;
			}
			return -1;
		}
		
		int circut_gas_greed(vector<int> &gas, vector<int> &cost){
			int cur_sum, total, start, i, n;

			n=gas.size();
			for (i=0;i<n;i++){
				cur_sum+=gas[i]-cost[i];
				total+=gas[i]-cost[i];
				if (cur_sum<0){
					start=i+1;
					cur_sum=0;
				}
			}
			if (total < 0) return -1;
			return start;
		}
};
int main (){
	return 0;
}

