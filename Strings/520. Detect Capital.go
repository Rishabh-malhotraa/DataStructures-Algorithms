package main

func isUpperCase(word string) bool {
	for _, ch := range word {
		if x := ch - 'A'; x < 0 || x >= 26 {
			return false
		}
	}
	return true
}
func isLowerCase(word string) bool {

	for _, ch := range word {
		if x := ch - 'a'; x < 0 || x >= 26 {
			return false
		}
	}
	return true

}
func isPascalCase(word string) bool {
	return isUpperCase(word[:1]) && isLowerCase(word[1:])
}

func detectCapitalUse(word string) bool {
	return (isUpperCase(word) || isLowerCase(word) || isPascalCase(word))
}
