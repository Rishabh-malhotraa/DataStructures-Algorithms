package main

import "math"

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxProfit(prices []int) int {
	buy, profit := math.MaxInt32, 0

	for _, price := range prices {
		if price < buy {
			buy = price
		} else {
			profit = Max(profit, price-buy)
		}
	}
	return profit
}
