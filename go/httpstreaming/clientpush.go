package main

import (
	"fmt"
	"io"
	"net/http"
)

func panicerr(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {

	reader, writer := io.Pipe()
	// NOT a great idea to ignore Close errors
	defer reader.Close()
	defer writer.Close()

	go func() {
		// This gorotine will pull data, through the client.Do call
		// that calls the reader on a loop forever.
		fmt.Println("creating request with stream")
		req, err := http.NewRequest("POST", "http://localhost:8080", reader)
		panicerr(err)
		fmt.Println("created request with stream")
		fmt.Println("performing request")
		client := http.Client{}
		res, err := client.Do(req)
		panicerr(err)
		fmt.Printf("got response: %q\n", res)
	}()

	// The main go routine keeps pushing data
	count := 0
	for {
		count += 1
		writer.Write([]byte(fmt.Sprintf("MESSAGE[%d]\n", count)))
	}

	fmt.Println("exiting")
}
