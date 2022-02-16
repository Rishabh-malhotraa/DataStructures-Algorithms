package main

import "sort"

func comparator(a int, b int) bool {
	return a < b
}

func sortString(word string) string {
	s := []rune(word)

	sort.Slice(s, comparator)

	return string(s)
}

func findTheDifference(s string, t string) byte {

	var cache map[rune]int

	var diff string
	for _, el := range s {
		cache[el] = cache[el] + 1
	}

	for _, el := range t {
		count, _ := cache[el]

		if count > 0 {
			cache[el] = cache[el] - 1
		} else {
			diff = diff + string(el)
		}
	}
	for k, v := range cache {
		for ; v > 0; v-- {
			diff = diff + string(k)
		}
	}
	return byte(diff[0])
}
