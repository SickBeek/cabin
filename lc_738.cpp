#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	public:
		bool checkNum(int num) {
			int digit, t;

			digit=10;
			while (num){
				t=num%10;
				if (digit>=t) digit=t; //monotone increasing
				else return false;
				num/=10;
			}
			return true;
		}

		int monotone_up_brutal(int n){
			int i;
			for (i=n;i>=0;i--){
				if (checkNum(i)) return i;
			}
			return 0;
		}

		int monotone_up(int n){
			string str=to_string(n);

			int i, size;

			size=str.size();
			for (i=size-1;i>0;i--){

			}

		}


		

};

int main (){
	return 0;
}
