#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
    public:
	int mySqrt(int x) {
		switch (x){
			case 0: return 0;
			case 1: return 1;
			case 2: return 1;
			case 3: return 1;
			case 4: return 2;
			case 5: return 2;
		}

		long left, right, mid;
		long long temp=0;
		left=2;
		right=int(x/2);

		while (left <right){
			//mid =(left-right)/2+right;
			mid=(right-left)/2+left;

			temp=(long long)mid*mid;
			if (temp==x){
				return mid;
			}
			else if (temp<x){
				left=mid+1;
				temp=(long long)left*left;
				if (temp>x){
					return mid;
				}
			}
			else{
				right=mid;
			}
		}
		return -1;
	}

	int mySqrt_Newton(int x){
		long r = x;
		long long temp=(long long)r*r;
		while (temp> x){
			temp=(long long)r*r;
			r = (r + x/r) / 2;
		}
		return r;
	}
};


int main (){
	Solution sol=Solution();
	int temp =2147395599;
	long mul1=(long long)temp*temp;
	long double mul2=(long long)temp*temp;
	long long mul3=(long long)temp*temp;
	/*
	cout<<temp<<endl;
	cout<<mul1<<endl;
	cout<<mul2<<endl;
	cout<<mul3<<endl;
	cout<<sizeof(temp)<<" "<<sizeof(mul1)<<" "<<sizeof(mul2)<<" "<<sizeof(mul3)<<" "<<endl;
	//cout<<2147395599*2147395599<<endl;
	*/

	//assert(sol.mySqrt(2147395599)==46339);
	//assert(sol.mySqrt(8)==2);
	cout<<sol.mySqrt_Newton(10)<<endl;
	cout<<sol.mySqrt(temp)<<endl;
    return 0;
}
