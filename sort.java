class Solution {
	public String customSortString(String ord, String str){
		int cnts[]=new int[26];  //default value 0

		for (char c: str.toCharArray()){
			cnts[c-'a']++;
		}

		var sb=new StringBuilder();

		for (char c: ord.toCharArray()){
			while (cnts[c-'a'] >0){
				sb.append(c);
				cnts[c-'a']--;
			}
		}

		for (char c='a';c<='z';c++){ //letters not in ord
			while (cnts[c-'a'] >0){
				sb.append(c);
				cnts[c-'a']--;
			}
		}
		return sb.toString();
	}
}

