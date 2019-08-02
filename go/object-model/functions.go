package main

import "fmt"

type Adder func(int, int) int

// Same type as Adder
func add(a int, b int) int {
	return a + b
}

func abstractedAdd(a Adder, b int, c int) int {
	return a(b, c)
}

type ObjectAdder struct{}

func (o *ObjectAdder) Add(a int, b int) int {
	return a + b
}

func main() {
	var a Adder
	fmt.Printf("Adder: %v\n", a)
	a = add
	fmt.Printf("Adder initialized: %v\n", a)
	fmt.Printf("func: %d + %d = %d\n", 1, 1, abstractedAdd(a, 1, 1))
	fmt.Printf("func: %d + %d = %d\n", 1, 1, abstractedAdd(add, 1, 1))

	var o *ObjectAdder
	fmt.Printf("func add: %T\n", add)
	fmt.Printf("object.Add: %T\n", o.Add)
	fmt.Printf("object: %d + %d = %d\n", 1, 1, abstractedAdd(o.Add, 1, 1))

	fmt.Printf("ObjectAdder.Add: %T\n", (*ObjectAdder).Add)
	fmt.Printf("ObjectAdder.Add: %d + %d = %d\n", 1, 1, (*ObjectAdder).Add(nil, 1, 1))
}
