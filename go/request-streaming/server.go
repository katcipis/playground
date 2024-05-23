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
		httpReq.TransferEncoding = []string{"identity"}
		httpReq.ContentLength = r.ContentLength
		client := &http.Client{}
		res, err := client.Do(httpReq)
		panicerr(err)
		defer func() {
			err = res.Body.Close()
			log.Printf("closed: error: %v", err)
		}()

		w.Header().Set("Content-Type", "text/event-stream; charset=utf-8")
		w.Header().Set("Transfer-Encoding", "chunked")
		w.WriteHeader(http.StatusOK)
		n, err := io.Copy(w, res.Body)
		log.Printf("written %d, error %v", n, err)
	})

	log.Println("starting to listen")
	log.Fatal(http.ListenAndServe(":8080", nil))
}
