#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Solution{
	string removeK_brutal(string num, int k){
		if (num.size()==k) return "0";

		int n, i;
		string str;

		n=num.size();
		while (k>0){
			n=num.size();
			i=0;  //start from the head again
			while (i<n-1 && num[i]<= num[i+1]) i++;
			num.erase(i,1); //erase the first peak
			k--;
		}
		
		i=0;
		while (i<num.size() && num[i]=='0') i++;
		num.erase(0, i+1);

		if (num=="") return "0";
		return num;
	}

	string removeK_stack(string num, int k){
		if (num.size()==k) return "0";

		int n, i;
		string str;

		n=num.size();
		for (i=0;i<n;i++){
			while (str.size()>0 && str.back()>num[i] && k>0){
				str.pop_back();
				k--;
			}
			str.push_back(num[i]);
		}

		i=0;
		while (i<str.size() && str[i]=='0') i++;
		str.erase(0 ,i);

		if (str=="") return "0";
		return str;
	}

};

int main(){
}
