import java.util.HashMap;

public class Main {
	public static void main (String []args){
		var sol=new Solution();
		String str="abcabcbb";

		int len=sol.lengthofLongestSubstring(str);
		System.out.println(len);
	}
}

class Solution{
	public int lengthofLongestSubstring(String s){
		if (s.length()==0) return 0;

		HashMap<Character, Integer> map =new HashMap<>();
		int maxlen, i, j;

		i=j=maxlen=0;
		for (;i<s.length();i++){
			if (map.containsKey(s.charAt(i))){
				j=Math.max(j, map.get(s.charAt(i))+1);
			}
			map.put(s.charAt(i), i);
			maxlen=Math.max(maxlen, i-j+1);
		}
		return maxlen;
	}
}
