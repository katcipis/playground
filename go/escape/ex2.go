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
	fmt.Println(aAddr)

	return a + b + c
}

func main() {
	fmt.Println(lala())
}
