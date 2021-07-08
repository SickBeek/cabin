#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
	public:
		int candy(vector<int> &rating){

			int sum, i, n, pre;
			n=rating.size();
			vector<int> dist(n, 1);
			i=1;
			for (;i<n;i++){
				if (rating[i]>rating[i-1]){
					dist[i]=dist[i-1]+1;
				}
			}
			
			for (i=n-2;i>=0;i--){
				if (rating[i]>rating[i+1]){
					dist[i]=max(dist[i], dist[i+1]+1);
				}
			}

			sum=0;
			for (i=0;i<n;i++){
				sum+=dist[i];
			}
			return sum;
		}

		int candy_O1(vector<int> &rating){
			int sum, up, down, peak, i;

			up=down=peak=0;
			sum=i=1;
			for (;i<rating.size();i++){
				if (rating[i-1]<rating[i]){
					peak=++up;
					down=0;

					sum+=up+1;
				}else if (rating[i-1]==rating[i]){
					peak=up=down=0;
					sum+=1;
				}else {
					up=0;
					down++;
					sum+=1+down+(peak >= down ?-1:0);
				}
			}
			return sum;
		}

};

int main (){
	return 0;
}
