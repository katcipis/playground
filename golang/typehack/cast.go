package main

import "fmt"

func main() {
	var a int
	var b interface{} = a
	c := b.(int)
	fmt.Println(c)
}
