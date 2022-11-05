package main

import "fmt"

func twoSum(nums []int, target int) []int {
	alreadySeen := make(map[int]int)
	for i, value := range nums {
		var needed = target - value
		if val, ok := alreadySeen[needed]; ok {
			return []int{i, val}
		}
		alreadySeen[value] = i
	}
	return []int{}
}

func CompareArrays(a []int, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func Test(nums []int, target int, expected []int) {
	var computed = twoSum(nums, target)
	fmt.Print("nums = ", nums, ".   computed = ", computed, " ---- ")
	if CompareArrays(computed, expected) {
		fmt.Println("pass")
	} else {
		fmt.Println("FAIL: expected ", expected)
	}
}

func main() {
	Test([]int{2, 7, 11, 15}, 9, []int{0, 1})
}
