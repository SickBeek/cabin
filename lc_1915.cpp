#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string s) {
        int n = s.size();
        long long res = 0;
        int i, j, f[1024], now;

        for (i = 0; i < 1024; ++i) f[i] = 0;
        f[0] = 1;
        now = 0;
        for (i = 0; i < n; ++i){
            j = (s[i] - 'a'); //b=1, c=2, .....
            now ^= (1<<j);  //mark
            res += f[now];
            for (j = 0; j < 10; ++j)
                res += f[now ^ (1<<j)];

            ++f[now];
        }
        return res;
    }
};

int main (){
	Solution sol;
	string str="bbaa";

	sol.wonderfulSubstrings(str);
	return 0;
}
