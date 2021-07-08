#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void print_stars(int num){
			int space_num, star_num;
			space_num=star_num=0;

            for (int i=0;i<num;i++){
				star_num=2*i+1;
				space_num=(2*num-1-star_num)/2;
				
				for (int j=0;j<space_num;j++)
					cout<<" ";

				for (int j=0;j<star_num;j++)
					cout<<"*";

				for (int j=0;j<space_num;j++)
					cout<<" ";
				cout<<endl;
			}
        }

		vector<vector<int>> generateMatrix(int n){
			vector<vector<int>> result(n, vector<int>(n, 0));
			int start_x, start_y, loop, mid, count, offset, i, j;
			start_x=start_y=0;
			i=j=0;
			loop=mid=n/2;
			count=offset=1;

			while (loop--){
				i=start_x;
				j=start_y;

				for (;j<start_y+n-offset;j++){
					result[i][j]=count++;
				}

				for (;i<start_x+n-offset;i++){
					result[i][j]=count++;
				}

				for (;j>start_y;j--){
					result[i][j]=count++;
				}

				for (;i>start_x;i--){
					result[i][j]=count++;
				}

				start_x++;
				start_y++;
				offset+=2;
			}

			if (n%2){
				result[mid][mid]=count;
			}
			return result;
		}
};


int main (){
	Solution sol=Solution();
	//sol.print_stars(5);
	auto result=sol.generateMatrix(4);
	for (auto iter_x=result.cbegin();iter_x!=result.cend();iter_x++){
		for (auto iter_y=(*iter_x).cbegin();iter_y!=(*iter_x).cend();iter_y++){
			cout<<*iter_y<<"  ";
		}
		cout<<endl;
	}
    return 0;
}

/*
def generateMatrix(num):
	result, loop=[], n*n+1
	while loop>1:
		loop, hi=loop-len(result), loop
		result=[range(loop, hi)]+zip(*result[::-1])
	return result
*/
