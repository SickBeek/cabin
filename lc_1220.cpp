#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	vector<string> res;
	string path;
	char vowels[5];
	int count;

	public:
	int countVowelPermutation(int n){

		vowels[0]='a';
		vowels[1]='e';
		vowels[2]='i';
		vowels[3]='o';
		vowels[4]='u';
		count=0;
		combine(n);
		cout<<count<<endl;
		return count;
	}

	void combine(int n){
		if (path.size()==n){
//			for (auto p: path){
//				cout<<p;
//			}
//			cout<<endl;
			count++;
			return;
		}
		
		for (int i=0;i<5;i++){
			if (path.size()>0){
				switch (path.back()){
					case 'a': if (i!=1) continue; break;
					case 'e': if (i!=0 && i!=2) continue; break;
					case 'i': if (i==2) continue; break;
					case 'o': if (i!=2 && i!=4) continue; break;
					case 'u': if (i!=0) continue; break;
				}
			}
			path.push_back(vowels[i]);
			combine(n);
			path.pop_back();
		}
	}
};

int main (){
	Solution sol;
	sol.countVowelPermutation(5);
	return 0;
}
