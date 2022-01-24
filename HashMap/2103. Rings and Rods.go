package main

func countPoints(rings string) int {
	n := len(rings)

	rods := make([]map[byte]bool, 10)
	for i := 0; i < 10; i++ {
		rods[i] = map[byte]bool{}
	}

	for i := 0; i < n; i += 2 {
		value, position := rings[i], rings[i+1]-'0'
		rods[position][value] = true
	}

	count := 0

	for _, list := range rods {
		if len(list) == 3 {
			count++
		}
	}
	return count
}
