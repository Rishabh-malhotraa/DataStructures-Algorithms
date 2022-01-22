package main

import "sort"

func Min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func highFive(items [][]int) [][]int {

	cache := make(map[int][]int)
	var result [][]int
	for _, value := range items {
		cache[value[0]] = append(cache[value[0]], value[1])
	}

	for key, nums := range cache {
		sort.Slice(nums, func(a, b int) bool {
			return nums[a] > nums[b]
		})

		sum := 0
		for i, num := range nums {
			if i == 5 {
				break
			}
			sum += num
		}

		size := Min(len(nums), 5)

		result = append(result, []int{key, sum / size})
	}

	sort.Slice(result, func(a, b int) bool {
		return result[a][0] < result[b][0]
	})

	return result
}
