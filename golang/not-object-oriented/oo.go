package main

import "fmt"

type operation func(int, int) int

type calculator interface {
	Add(a int, b int) int
	Sub(a int, b int) int
}

func complexCalculation(a int, b int, calc calculator) int {
	c := calc.Add(a, b)
	d := calc.Sub(b, a)
	return calc.Add(c, d)
}

func add(a int, b int) int {
	return a + b
}

func sub(a int, b int) int {
	return a - b
}

type composedCalculator struct {
	Add operation
	Sub operation
}

func main() {
	calc := composedCalculator{
		Add: add,
		Sub: sub,
	}
	fmt.Println("Result: %d", complexCalculation(10, 20, calc))
	fmt.Println("Not as OO as you would think")
}
