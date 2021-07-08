#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution{
	public:
		bool isInterLeave(string s1, string s2, string s3){
			int ptr1, ptr2, ptr3, tail;

			ptr1=ptr2=ptr3=0;
			while (ptr1<s1.size() && ptr2<s2.size() &&ptr3<s3.size()){
				if (s3[ptr3]==s1[ptr1]){
					ptr1++; ptr3++;
				}else if (s3[ptr3]==s2[ptr2]){
					ptr2++; ptr3++;
				}else{
					return false;
				}
			}

			if (ptr1==0 || ptr2==0)
				return false;

			if (ptr1!=s1.size()-1){
				while (ptr1<s1.size()){
					if (s3[ptr3]!=s1[ptr1]){
						return false;
					}
					ptr1++; ptr3++;
				}
				return true;
			}

			if (ptr2!=s2.size()-1){
				while (ptr2<s2.size()){
					if (s3[ptr3]!=s2[ptr2]){
						return false;
					}
					ptr2++; ptr3++;
				}
				return true;
			}
			return false;
		}
};

int main (){
	return 0;
}
