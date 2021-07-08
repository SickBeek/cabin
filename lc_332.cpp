#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution{
	unordered_map<string, map<string, int>> targets;

	bool combine(int count, vector<string>& result){
		if (result.size()==count+1){
			return true;
		}

		for (auto &tar: targets[result.back()]){
			if (tar.second > 0){  //isvisited
				result.push_back(tar.first);
				tar.second--;
				if (combine(count, result)) return true;
				tar.second++;
				result.pop_back();
			}
		}
		return false;
	}

	public:
	vector<string> findItinerary(vector<vector<string>& tickets>){
		vector<string> result;
		for (const vector<string>& vec: tickets){
			targets[vec[0]][vec[1]]++;
		}
		result.push_back("JFK");
		combine(tickets.size(), result);
		return result;
	}
	
};

int main(){
	return 0;
}

