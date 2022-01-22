package main

import "math"

func Min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func maxDistToClosest(seats []int) int {
	n := len(seats)

	left, right := make([]int, n), make([]int, n)

	for i, _ := range left {
		left[i], right[i] = math.MaxInt32, math.MaxInt32
	}

	for i := 0; i < n; i++ {
		if seats[i] == 1 {
			left[i] = 0
		} else {
			previous := Min(0, i-1)
			if left[previous] != math.MaxInt32 {
				left[i] = left[previous] + 1
			}
		}
	}

	for i := n - 1; i >= 0; i-- {
		if seats[i] == 1 {
			right[i] = 0
		} else {
			next := Min(n-1, i+1)
			if right[next] != math.MaxInt32 {
				right[i] = right[next] + 1
			}
		}
	}

	distance := 0
	for i, _ := range left {
		if seats[i] != 1 {
			// fmt.Println(distance, left[i], right[i], i)
			distance = Max(distance, Min(left[i], right[i]))
		}
	}
	return distance
}
