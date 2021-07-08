#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class FindSumPairs{
	private:
		vector<int> nums1, nums2;
		int max1, min1, max2, min2;
		unordered_map<int, int> st1, st2;

	public:
		FindSumPairs(vector<int> &n1, vector<int> &n2){
			max1=min1=n1[0];
			max2=min2=n2[0];

			for (int i: n1){
				nums1.push_back(i);
				max1=(i>=max1)?i:max1;
				min1=(i<=min1)?i:min1;
				if (st1.find(i)==st1.cend()){
					//st1.insert(unordered_map::pair<>)
					st1.insert({i, 1});
				}else {
					st1.find(i)->second++;
				}
			}

			for (int i: n2){
				nums2.push_back(i);
				max2=(i>=max2)?i:max2;
				min2=(i<=min2)?i:min2;
				if (st1.find(i)==st1.cend()){
					st1.insert({i, 1});
				}else {
					st1.find(i)->second++;
				}
			}
			//nums1.assign(n1.begin(), n1.end());
			//nums2.assign(n2.begin(), n2.end());
		}

		void add(int index, int val){
			nums2.insert(nums.begin()+index, val);
		}

		int count(int tot){
			if (max1+max2<tot || min1+min2 >tot){
				return 0;
			}

			int count=0;
			for (int i=0;i<nums1.size();i++){
				if (st2.find(tot-i)!=st2.end()){
					count+=st2.find(i)->second;
				}
			}
			return count;
		}
};

int main (){
	vector<int> num1={1, 1, 2, 2, 2, 3};
	vector<int> num2={1, 4, 5, 2, 5, 4};

	FindSumPairs find1=FindSumPairs(num1, num2);
	return 0;
}
