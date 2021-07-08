#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size()==1) return stones[0];

        int i, s, diff, idx;
        sort(stones.begin(), stones.end());

        while (true){
            s=stones.size();
            if (s==0)
                return 0;
            else if (s==1)
                return stones[0];

			idx=0;
            if (stones[s-2]<stones[s-1]){
                diff=stones[s-1]-stones[s-2]; //new weight
                cout<<diff<<endl;
                for (i=0;i<s-2;i++){
                    if (diff<=stones[i]){
                        idx=i;
                        break;
                    }
                }
                idx=min(idx, s-2);
                stones.insert(stones.begin()+idx, diff);
            }
            stones.pop_back(); stones.pop_back();
        }
        return 0;
    }

    int lastStoneWeight_arbitrary(vector<int>& stones) {
		int i,j, sum, half;

		sum=0;
		for (auto s: stones){
			sum+=s;
		}

		half=sum/2;
		vector<int> dd(half, 0);
		for (i=0;i<stones.size();i++){
			for (j=half;j>=stones[i];j--){   //if stone[i]>half, skip
				dd[j]=max(dd[j], dd[j-stones[i]]+stones[i]);
			}
		}
		return sum-dd[half]-dd[half];
	}
};

int main (){
	Solution sol;
	vector<int> stones={1,2,1,7,8,4};

	cout<<sol.lastStoneWeight(stones)<<endl;
	return 0;
}
