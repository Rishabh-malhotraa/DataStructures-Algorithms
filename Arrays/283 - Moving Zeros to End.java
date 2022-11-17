package Arrays;


class Solution {
  public void moveZeroes(int[] nums) {
    int swaps = 0;
    for (int i = 0; i < nums.length; i++) {
      int num = nums[i];
      if (num == 0)
        swaps++;
      else {
        int temp = nums[i];
        nums[i] = nums[i - swaps];
        nums[i - swaps] = temp;
      }
    }
  }
}