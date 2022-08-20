package main

import (
	"fmt"
)

type x struct {
	a int
}

func eq[T comparable](a, b T) bool {
	return a == b
}

func main() {
	fmt.Println(eq(1, 1))
	fmt.Println(eq(1, 2))

	fmt.Println(eq(x{1}, x{1}))
	fmt.Println(eq(x{1}, x{2}))
}
