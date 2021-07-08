import java.util.List;
import java.util.ArrayList;

public class Main {
	public static void main (String[] args){
		var sol=new Solution();
		sol.countVowelPermutation(5);
	}
}

class Solution {
    public int countVowelPermutation(int n) {
        List<List<Character>> res = new ArrayList<>();
		char vowels[]=new char[5];

		vowels[0]='a';
		vowels[1]='e';
		vowels[2]='i';
		vowels[3]='o';
		vowels[4]='u';

        backtracking(res, new ArrayList<>(),vowels, n);
        return res.size();
    }

    public void backtracking(List<List<Character>> res, List<Character> path,char[] vowels, int n){
        if (path.size() == n) {
			for (var p:path){
				System.out.print(p);
			}
			System.out.println();
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < vowels.length; i++) {
			if (path.size()>0){
			if (path.get(path.size()-1)=='a'){ if (i!=1) continue; }
			if (path.get(path.size()-1)=='e'){ if (i!=0) continue; if (i!=2) continue; }
			if (path.get(path.size()-1)=='i'){ if (i==2) continue; }
			if (path.get(path.size()-1)=='o'){ if (i!=2) continue; if (i!=4) continue; }
			if (path.get(path.size()-1)=='u'){ if (i!=0) continue; }
			}

            path.add(vowels[i]);
            backtracking(res, path, vowels, n);
            path.remove(path.size() - 1);
        }
    }
}

