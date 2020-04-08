package main

import (
	"fmt"
)

func lala(p int) {
	var a int
	var b int
	var c int

	fmt.Println("p", &p)
	fmt.Println("a", &a)
	fmt.Println("b", &b)
	fmt.Println("c", &c)
}

func main() {
	lala(0)
	lala(1)
}
