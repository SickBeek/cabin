class Solution {
	public int findIntegers(int num){
		StringBuilder sb=new StringBuilder(Integer.toBinaryString(num)).reverse();
		int n=sb.length();

		int a[]=new int[n];
		int b[]=new int[n];
		a[0]=b[0]=1;
	}
}

