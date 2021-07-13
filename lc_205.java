import java.util.Arrays;

class Main{
	public static void main (String[] args){
		var sol=new Solution();
		System.out.println(sol.isIsomorphic("add", "egg"));

	}
}

class Solution {
	public boolean isIsomorphic_wrong(String s, String t){
		int len1, len2;

		len1=s.length();
		len2=t.length();
		int pos1[]=new int [len1];
		int pos2[]=new int [len2];
		int i, idx1, idx2;

		for (i=0;i<len1;i++){
			pos1[i]=s.charAt(i)-'a';
			pos2[i]=t.charAt(i)-'a';
		}
		
		for (i=0;i<s.length();i++){
			idx1=s.charAt(i)-'a';
			idx2=t.charAt(i)-'a';

			if (pos1[idx1]==-1){
				pos1[idx1]=i;
			}else {
				if(pos1[idx1]!=pos2[idx2]){
					return false;
				}
				pos1[idx1]=i;
			}

			if (pos2[idx2]==-1){
				pos2[idx2]=i;
			}else {
				if(pos1[idx1]!=pos2[idx2]){ //last time, not equal
					return false;
				}
				pos2[idx2]=i;

				if (pos2[idx2]!=pos1[idx1]){  //this time, !=
					return false;
				}
			}
		}
		return true;
	}

	public boolean isIsomorphic(String s, String t){
		int []pos1=new int [128];
		int []pos2=new int [128];
		int i;

		Arrays.fill(pos1, -1);
		Arrays.fill(pos2, -1);

		for (i=0;i<s.length();i++){
			if (pos1[s.charAt(i)]!=pos2[t.charAt(i)]){
				return false;
			}
			pos1[s.charAt(i)]=i;
			pos2[t.charAt(i)]=i;
		}

		return true;
	}
}

