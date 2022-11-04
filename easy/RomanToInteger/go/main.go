package main

import "fmt"

func romanToInt(s string) int {
	var result int = 0
	var prev rune = ' '
	for _, c := range s {
		switch c {
		case 'I':
			result += 1
		case 'V':
			if prev == 'I' {
				result += 3
			} else {
				result += 5
			}
		case 'X':
			if prev == 'I' {
				result += 8
			} else {
				result += 10
			}
		case 'L':
			if prev == 'X' {
				result += 30
			} else {
				result += 50
			}
		case 'C':
			if prev == 'X' {
				result += 80
			} else {
				result += 100
			}
		case 'D':
			if prev == 'C' {
				result += 300
			} else {
				result += 500
			}
		case 'M':
			if prev == 'C' {
				result += 800
			} else {
				result += 1000
			}

		}
		prev = c
	}
	return result
}

func Test(roman string, expected int) {
	var computed = romanToInt(roman)
	fmt.Print("roman = ", roman, ".   computed = ", computed, " ---- ")
	if computed == expected {
		fmt.Println("pass")
	} else {
		fmt.Println("FAIL: expected ", expected)
	}
}

func main() {
	Test("III", 3)
	Test("I", 1)
	Test("III", 3)
	Test("XV", 15)
	Test("MDCLXVI", 1666)
	Test("IV", 4)
	Test("IX", 9)
	Test("XL", 40)
	Test("XC", 90)
	Test("CD", 400)
	Test("CM", 900)
	Test("MMMCMXCIX", 3999)
}
