package main

import (
	"io"
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
		httpReq, err := http.NewRequest(http.MethodPost, "http://localhost:8081", r.Body)
		panicerr(err)
		//httpReq.TransferEncoding = []string{"identity"}
		client := &http.Client{}
		res, err := client.Do(httpReq)
		panicerr(err)
		n, err := io.Copy(w, res.Body)
		log.Printf("written %d, error: %v", n, err)
		panicerr(err)
	})

	log.Println("starting to listen")
	log.Fatal(http.ListenAndServe(":8080", nil))
}
