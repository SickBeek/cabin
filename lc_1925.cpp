#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	public:
	int countTriples_2mn(int limit){
		int a,b,c, m, n;

		c=0;
		m=2;

		while (c<limit){
			for (n=1;n<m;n++){
				a=m*m-n*n;
				b=2*m*n;
				c=m*m+n*n;
			}

			if (c>limit)
				break;

			m++;

			cout<<a<<" "<<b<<" "<<c<<" "<<endl;
		}
		return 0;
	}
};

int main (){
	Solution sol;
	int n=20;

	sol.countTriples_2mn(n);
	return 0;
}
