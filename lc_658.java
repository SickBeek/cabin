public class Main{
	public static void main (String[] args){
	}
}

class Solution{
	public List<Interger> findClosestElments(int []arr, int k, int x){
		var result=new List<Interger>();
		int i, idx, left, right;

		if (arr[0]> x){
			for (i=0;i<arr.length;i++){
				k--;
				result.add(arr[i]);
				if (k==0) return result;
			}
		}

		if (x > arr[arr.length-1]){
			for (i=arr.lengt-1;i>=0;i--){
				k--;
				result.add(arr[i]);
				if (k==0) return result;
			}
		}
		
		idx=binarySearch(arr, x);
		left=idx-1;
		right=idx;
		while (left>=0 && right<arr.length){
			if (x-arr[left]<=arr[right]-x){
				result.add(arr[left]);
				left--;
				k--;
			}else {
				result.add(arr[right[]);
				right++;
				k--;
			}
			if (k==0){
				return result;
			}
		}

		if (left<0){
			while (k--){
				result.add(arr[right++]);
			}
			return result;
		}

		if (right>=arr.length){
			while (k--){
				result.add(arr[left--]);
			}
			return result;
		}
	}

	public int binarySearch(int []arr, int x){
		int left, mid, right;

		left=0;
		right=arr.size();

		while (left<right){
			mid=(right-left)/2 + left;
			if (arr[mid]<x){
				left=mid+1;
			}else {   //find the left most element when duplicates occur
				right=mid;  //despite hitted, move left
			}
		}
		return left;
	}
}
