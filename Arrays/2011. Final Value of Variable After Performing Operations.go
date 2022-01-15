package main

func checkIncrement(s string) bool {
	for _, ch := range s {
		if ch == '+' {
			return true
		}
	}
	return false
}

func finalValueAfterOperations(operations []string) int {
	count := 0

	for _, operation := range operations {
		if checkIncrement(operation) {
			count++
		} else {
			count--
		}
	}
	return count
}
