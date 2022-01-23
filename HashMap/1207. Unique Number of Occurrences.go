package main

func uniqueOccurrences(arr []int) bool {
	freqMap := make(map[int]int)

	for _, num := range arr {
		freqMap[num] += 1
	}

	set := make(map[int]bool)

	for _, freq := range freqMap {
		if _, isPresent := set[freq]; isPresent {
			return false
		}
		set[freq] = true
	}
	return true
}
