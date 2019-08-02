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

type composedCalculator struct {
	//The stupid thing here is that I dont have any state
	//I just want to represent the composition of multiple functions
	//as a protocol. Very sad :-(
}

func (c composedCalculator) Add(a int, b int) int {
	return a + b
}

func (c composedCalculator) Sub(a int, b int) int {
	return a - b
}

func main() {
	fmt.Println("Result: ", complexCalculation(10, 20, composedCalculator{}))
}
