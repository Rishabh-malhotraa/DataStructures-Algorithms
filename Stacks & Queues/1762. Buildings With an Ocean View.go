package main

func findBuildings(heights []int) []int {
	var stack []int

	for i, height := range heights {
		for len(stack) != 0 && height >= heights[stack[len(stack)-1]] {
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i)
	}

	return stack
}
