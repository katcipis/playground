package main

import (
	"fmt"
	"math/rand"
)

func main() {
	const iters = 100
	const percent = 20

	count := 0
	for i := 0; i < iters; i++ {
		res := rand.Intn(iters)
		if res < percent {
			count += 1
		}
	}

	fmt.Println(count)
}
