package main

import (
	"fmt"
	"log"
	"net/http"
)

func panicerr(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Println("received request, starting to read it")
		defer func() {
			err := r.Body.Close()
			panicerr(err)
		}()

		buffer := make([]byte, 256)
		var err error
		for err == nil {
			_, err = r.Body.Read(buffer)
			fmt.Printf("received: %s\n", string(buffer)+"\n")
		}

		fmt.Println("streaming ended")
	})

	fmt.Println("starting to listen")
	log.Fatal(http.ListenAndServe(":8080", nil))
}
