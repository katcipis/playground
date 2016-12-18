package main

import "fmt"

func iterator() func() int {
	a := 0
	return func() int {
		a++
		return a
	}
}

func main() {
	itera := iterator()
	iterb := iterator()

	fmt.Printf("itera 1: %d\n", itera())
	fmt.Printf("itera 2: %d\n", itera())
	fmt.Printf("itera 3: %d\n", itera())

	fmt.Printf("iterb 1: %d\n", iterb())
	fmt.Printf("iterb 2: %d\n", iterb())
	fmt.Printf("iterb 3: %d\n", iterb())
}
