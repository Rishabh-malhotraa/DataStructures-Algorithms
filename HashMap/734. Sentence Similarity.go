package main

/*

["an","extraordinary","meal"]
["one","good","dinner"]
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]


MULTIMAP SOLUTION
*/

func checkPresent(s string, arr []string) bool {
	for _, word := range arr {
		if word == s {
			return true
		}
	}

	return false
}

func areSentencesSimilar(A []string, B []string, words [][]string) bool {
	if len(A) != len(B) {
		return false
	}

	cache := make(map[string][]string)

	for _, word := range words {
		u, v := word[0], word[1]
		cache[u] = append(cache[u], v)
		cache[v] = append(cache[v], u)
	}
	for i := range A {
		if A[i] == B[i] {
			continue
		} else if value, valid := cache[A[i]]; valid && !checkPresent(B[i], value) {
			return false
		} else if value, valid := cache[B[i]]; valid && !checkPresent(A[i], value) {
			return false
		}
	}
	return true
}
