#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverse_all(string &s, string::size_type begin, string::size_type end){
		char tmp;
		string::size_type i, j;
		for (i=begin, j=end;i<j;i++, j--){
			tmp=s[i];
			s[i]=s[j];
			s[j]=tmp;
			//swap(s[i],s[j]);
		}
	}

	void trim_space(string &s){
		string::size_type i,j;
		char target=' ';
		i=j=0;

		//trim head spaces
		while (j< s.size() && s[j]==target){
			j++;
		}
		
		//trim duplicate spaces within
		for (;j<s.size();j++){
			if (j-1>0 && s[j-1]==s[j] && s[j]==target){
				continue;
			}else {
				s[i++]=s[j];
			}
		}

		//trim last space

		if (i-1 >0 && s[i-1]==' ')
			s.resize(i-1);
		else
			s.resize(i);
	}

	string reverse_words(string s){
		trim_space(s);
		reverse_all(s, 0, s.size()-1);

		string ::size_type i,j;  //slow &fast pointers
		char target=' ';

		i=j=0;
		while (j<s.size()){
			if (s[j]==target){
				reverse_all(s, i, j-1);
				i=j+1;
			}
			j++;
		}
		reverse_all(s, i, j-1);
		return s;
	}
	
	bool isPrime(int n){
		if (n<2){
			return false;
		}

		int i;
		for (i=2;i<sqrt(n);i++){
			if (n%i==0)
				return false;
		}
		return true;
	}
};

int main (){
	Solution sol=Solution();
	string s="  Bob    Loves  Alice   ";
	string s2="   the sky is blue   ";

	cout<<sol.reverse_words(s)<<'$'<<endl;
return 0;
}
