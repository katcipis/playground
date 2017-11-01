package main

import (
	"fmt"
	"os/exec"
	"sync"
)

func main() {
	workers := 300
	wg := sync.WaitGroup{}
	wg.Add(workers)

	for i := 0; i < workers; i++ {
		go func() {
			cmd := exec.Command("sleep", "1")
			err := cmd.Run()
			if err != nil {
				fmt.Println(err)
			}
			wg.Done()
		}()
	}
	wg.Wait()
}
