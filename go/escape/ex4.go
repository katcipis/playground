package main

import (
	"fmt"
	"unsafe"
)

func lala() int {
	var a int
	var b int
	var c int

	aAddr := uintptr(unsafe.Pointer(&a))
	bAddr := uintptr(unsafe.Pointer(&b))
	cAddr := uintptr(unsafe.Pointer(&c))

	fmt.Printf("%X\n", aAddr)
	fmt.Printf("%X\n", bAddr)
	fmt.Printf("%X\n", cAddr)

	return a + b + c
}

func main() {
	lala()
	lala()
}
