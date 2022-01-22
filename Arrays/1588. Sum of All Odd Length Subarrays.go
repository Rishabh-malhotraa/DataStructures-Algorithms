package main

import "math"

func getSum(arr *[]int) int {
	sum := 0
	for _, value := range *arr {
		sum += value
	}
	return sum
}

func sumOddLengthSubarrays(arr []int) int {
	var sum int = 0

	for d := 0; d <= len(arr); d += 2 {
		for i, j := 0, d; j < len(arr); i, j = i+1, j+1 {
			newArray := arr[i : j+1]
			sum += getSum(&newArray)
			// fmt.Println(newArray, sum)
		}
	}
	return sum
}

// O(N) Solution

func sumOddLengthSubarraysII(arr []int) int {
	var sum int = 0
	n := len(arr)
	for i, num := range arr {
		contribution := math.Ceil(float64((i+1)*(n-i)) / float64(2))
		sum += int(contribution) * num
	}
	return sum
}

func sumOddLengthSubarraysIII(arr []int) int {
	var sum int = 0
	n := len(arr)
	for i, num := range arr {
		contribution := ((i+1)*(n-i)-1)/2 + 1
		sum += contribution * num
	}
	return sum
}
