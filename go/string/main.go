package main

import "fmt"

func main() {
	samplestr := "canção"

	fmt.Println("the idea of this code is to show that string behavior")
	fmt.Println("in go is not consistent and that implementation details leaks")
	fmt.Println("strings are actually byte slices and it behaves as one")

	fmt.Printf("string[%s]: len[%d] type[%T]\n", samplestr, len(samplestr), samplestr)
	fmt.Printf("string value being accessed through index: value[%d] type[%T]\n", samplestr[0], samplestr[0])

	fmt.Println("iterating a string won't return you its bytes, but runes")
	iterationsCount := 0
	for i, r := range samplestr {
		fmt.Printf("index[%d] value[%v] type[%T]\n", i, r, r)
		iterationsCount += 1
	}

	fmt.Printf("the len of the string is [%d] but the amount of iterations looping through it is [%d]\n", len(samplestr), iterationsCount)
	fmt.Println("quite inconsistent and showcases that it is not safe to use len or access a string through slice operations")
	fmt.Println("a string is a set of 'something' that has different cardinality depending on how you iterate through it")
}
