package Arrays;

/*
  Input: prices = [7,1,5,3,6,4]
  Output: 5
  Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
  Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 */


class Solution {
  public int maxProfit(int[] prices) {
  int minPrice = prices[0], profit = 0;
    for(int i =0 ; i< prices.length; i++){
      minPrice = Math.min(minPrice, prices[i]);
      profit = Math.max(profit, prices[i] - minPrice );
    }
    return profit;
  }
}