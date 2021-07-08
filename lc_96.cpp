#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

class Solution{
	public:
		int numTrees(int n){
			int *dd=new int[20];
			int i,j;

			dd[0]=dd[1]=1;
			dd[2]=2;
			for (i=3;i<=n;i++){
				for (j=0;j<i;j++){
					dd[i]+=dd[j]*dd[i-j];
				}
			}
			return dd[n];
		}
};

int main (){
	return 0;
}
