package main

func minOperations(boxes string) []int {
	n := len(boxes)
	left := make([]int, n)
	right := make([]int, n)
	count, ops := 0, 0

	for i, box := range boxes {
		left[i] += ops
		if box == '1' {
			count++
		}
		ops += count
	}

	ops, count = 0, 0
	for i := n - 1; i >= 0; i-- {
		right[i] += ops
		if boxes[i] == '1' {
			count++
		}
		ops += count
	}

	operations := make([]int, n)

	for i := range left {
		operations[i] = left[i] + right[i]
	}

	return operations
}
