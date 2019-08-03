package main

import "fmt"

func main() {

	fmt.Println(`
The idea of this code is to show that string behavior
in Go is not consistent and that implementation details leaks.
strings are actually byte slices and they behave as one to almost
all operations, but not all, hence inconsistent.
`)
	samplestr := "canção"
	fmt.Printf("string[%s]: len[%d] type[%T]\n", samplestr, len(samplestr), samplestr)

	fmt.Println(`
The length of a string behaves as a byte slice, giving a size in bytes,
not a size in valid characters (or runes).
Iterating the string with a numeric for will also get you byte slice behavior:
`)
	bytesCount := 0
	for i := 0; i < len(samplestr); i++ {
		b := samplestr[i]
		fmt.Printf("index[%d] value[%v] type[%T]\n", i, b, b)
		bytesCount += 1
	}
	fmt.Printf("iterations through len: %d\n", bytesCount)

	fmt.Println(`
But iterating the string with range will get you rune slice behavior.
This is so inconsistent that you will see something very odd happening, the index
on the for loop will increment by two on some iterations.
`)
	runesCount := 0
	for i, r := range samplestr {
		fmt.Printf("index[%d] value[%v] type[%T]\n", i, r, r)
		runesCount += 1
	}
	fmt.Printf("iterations through range: %d\n", runesCount)

	fmt.Println(`
Summing up: len and index operations behave as byte slice
but range iteration behaves as a rune slice.

Quite inconsistent and showcases that it is not safe to use
len or index a string (it will only work for ASCII).

A string is a set of 'something' that has different
cardinality and values depending on how you iterate or access it.
`)
}
