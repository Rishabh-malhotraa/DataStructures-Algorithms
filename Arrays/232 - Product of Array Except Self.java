package Arrays;
import java.util.ArrayList;


/*
 * 
 * 1 2 3 4
 * 1 
 * 1 2
 * 
 */


class Solution {
  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] result = new int[n], left = new int[n], right = new int[n];


    for (int i =0 ; i < n; i++)
      left[i] = nums[i] * (i == 0 ? 1 : left[i-1]) ;

    for (int i =n-1 ; i >=0; i--)
      right[i] = nums[i] * (i == n-1? 1 : right[i+1]);
    

    for (int i = 0; i< n; i++)
    {
      int leftVal = (i == 0) ? 1 : left[i-1];
      int rightVal = (i == n-1) ? 1: right[i+1];
      result[i] = leftVal * rightVal;
    }
    
    return result;
  }
}