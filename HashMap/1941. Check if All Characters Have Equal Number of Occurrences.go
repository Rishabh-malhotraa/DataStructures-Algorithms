package main

func areOccurrencesEqual(s string) bool {
	freq := make(map[rune]int)

	for _, ch := range s {
		freq[ch]++
	}

	count := -1
	for _, value := range freq {
		if count == -1 {
			count = value
		} else if count != value {
			return false
		}
	}
	return true
}
