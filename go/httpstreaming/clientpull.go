package main

import (
	"fmt"
	"io"
	"net/http"
)

type stream struct {
	counter int
}

func (s *stream) Read(b []byte) (int, error) {
	s.counter += 1
	fmt.Printf("read called: %d\n", s.counter)
	for i := range b {
		b[i] = 'K'
	}
	return len(b), nil
}

func panicerr(err error) {
	if err != nil {
		panic(err)
	}
}

func newStream() io.Reader {
	return &stream{}
}

func main() {
	fmt.Println("creating request with stream")
	req, err := http.NewRequest("POST", "http://localhost:8080", newStream())
	panicerr(err)
	fmt.Println("created request with stream")
	fmt.Println("performing request")
	client := http.Client{}
	res, err := client.Do(req)
	panicerr(err)
	fmt.Printf("got response: %q\n", res)
}
