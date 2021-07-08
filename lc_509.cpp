#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

class Solution{
	public:
		int fib1(int n){
			int first, second;
			if (n==0) return 0;
			if (n==1) return 1;

			while (true){
				first=first+second;
				n--;
				if (n==1) return first;

				second=first+second;
				n--;
				if (n==1) return second;
			}
			return -1;
		}

		int fib_recur(int n) {
			if (n==0) return 0;
			if (n==1) return 1;
			return fib_recur(n-2) + fib_recur(n-1);
		}

		int fib_tail_recur(int n, int f, int s){
			if (n==0) return 0;
			if (n<=2) return 1;
			if (n==3) return f+s;
			return fib_tail_recur(n-1, s, f+s);
		}

		int fib_dp(int n){
			int dd0, dd1, sum;

			if (n==0) return 0;
			if (n==1) return 1;

			for (int i=2;i<=n;i++){
				sum=dd0+dd1;
				dd0=dd1;
				dd1=sum;
			}
			return dd1;
		}
};

int main (){
	Solution sol;
	int start, end, result;

	start=clock();
	result=sol.fib_tail_recur(20, 1, 1);
	end=clock();
	cout<<result<<endl;
	
	cout<<"Execution Time: "<<(double)((end-start)/CLOCKS_PER_SEC)<<endl;
	return 0;
}

