package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	tty, err := os.Open("/dev/tty")
	if err != nil {
		log.Fatal(err)
	}
	buff := make([]byte, 1024)
	n, err := tty.Read(buff)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(string(buff[:n]))
}
