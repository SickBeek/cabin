#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	public:
		int findMaxForm(vector<string> &strs,const int m, const int n){
			int **dd=new int *[m+1];
			int i, j, ones, zeros;

			for (i=0;i<=m;i++){
				dd[i]=new int[n+1];
				for (j=0;j<=n;j++){
					dd[i][j]=0;
				}
			}
			
			for (string str:strs){ //traverse items
				ones=zeros=0;
				for (char c: str){
					if (c=='0')
						zeros++;
					else if (c=='1')
						ones++;
				}

				//for (i=zeros;i<=m;i++){ //2 dimensions, cant forward traverse
				//	for (j=ones;j<=n;j++){
				
				for (i=m;i>=zeros;i--){
					for (j=n;j>=ones;j--){
						dd[i][j]=max(dd[i][j], dd[i-zeros][j-ones]+1);
					}
				}

				for (i=0;i<=m;i++){
					for (j=0;j<=n;j++){
						cout<<dd[i][j]<<" ";
					}
					cout<<endl;
				}
				cout<<endl;
		  }
			}
			return dd[m][n];
		}
};

int main (){
	Solution sol;
	vector<string> strs={"10","0001","111001","1","0"};

	cout<<sol.findMaxForm(strs, 5, 3)<<endl;
	return 0;
}
