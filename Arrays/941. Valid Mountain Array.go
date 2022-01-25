package main

// one pass -> walk up and then walk down

func validMountainArray(arr []int) bool {
	i, n := 0, len(arr)
	for i+1 < n && arr[i] < arr[i+1] {
		i++
	}
	if i == 0 || i == n-1 {
		return false
	}
	for i+1 < n && arr[i] > arr[i+1] {
		i++
	}
	return i == n-1
}

//  BOOTLEG LOGIC LOL
/*
func validMountainArray(arr []int) bool {

	n := len(arr)
	j := 0

	if n == 1 {
		return false
	}

	for i := 0; i < n-1; i++ {
		if arr[i] == arr[i+1] {
			return false
		} else if arr[i] > arr[i+1] {
			if i == 0 {
				return false
			}
			j = i
			break
		}
	}

	for ; j < n-1; j++ {
		// fmt.Println(arr[j] , arr[j+1], j)
		if arr[j] <= arr[j+1] {
			return false
		}
	}
	return true
}
*/
