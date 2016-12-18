package main

import "fmt"

type iterator struct {
	a int
}

func (i *iterator) iter() int {
	i.a++
	return i.a
}

func newIter() *iterator {
	return &iterator{
		a: 0,
	}
}

func main() {
	i := newIter()

	fmt.Printf("iter 1: %d\n", i.iter())
	fmt.Printf("iter 2: %d\n", i.iter())
	fmt.Printf("iter 3: %d\n", i.iter())
}
