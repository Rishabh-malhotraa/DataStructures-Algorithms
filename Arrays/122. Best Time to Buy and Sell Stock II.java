package Arrays;

class Solution {
  public int maxProfit(int[] prices) {
    int n = prices.length, profit = 0;
    for(int i = 1 ; i< n ; i++)
      // profit += (prices[i] - prices[i-1] > 0) ? prices[i] - prices[i-1] : 0;
      profit += Math.max(0, prices[i] - prices[i-1]);
    return profit;
  }
}