package main

import (
	"strings"
)

func getDate(day string) string {
	var foo []rune
	for _, ch := range day {
		if ch-'0' >= 0 && ch-'9' <= 9 {
			foo = append(foo, ch)
		}
	}

	if len(foo) == 1 {
		foo = append([]rune{'0'}, foo...)
	}

	return string(foo)
}

func reformatDate(date string) string {
	months := map[string]string{
		"Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04", "May": "05", "Jun": "06", "Jul": "07", "Aug": "08", "Sep": "09", "Oct": "10", "Nov": "11", "Dec": "12",
	}

	arr := strings.Split(date, " ")

	formatedDate := arr[2] + "-" + months[arr[1]] + "-" + getDate(arr[0])

	return formatedDate
}
