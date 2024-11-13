// Writer benchmarks creating multiple files on the given directory
// It wont delete the files, so keep that in mind.
package main

import (
	"context"
	"crypto/rand"
	"flag"
	"fmt"
	"log"
	"os"
	"os/signal"
	"sync"
	"sync/atomic"
	"time"

	"github.com/google/uuid"
)

func main() {
	fileSize := flag.Int("filesize", 1024, "filesize")
	duration := flag.Duration("duration", time.Minute, "how long the test will run")
	maxFiles := flag.Int("maxfiles", 1_000_000, "max files that will be created")
	writers := flag.Int("writers", 1, "how many concurrent writers")
	flag.Parse()

	ctx, cancel1 := context.WithTimeout(context.Background(), *duration)
	defer cancel1()
	ctx, cancel2 := signal.NotifyContext(ctx, os.Interrupt)
	defer cancel2()

	buffer := make([]byte, *fileSize)
	_, _ = rand.Read(buffer)

	fmt.Printf("==== running writer ====\n")
	fmt.Printf("duration: %v\n", *duration)
	fmt.Printf("maxfiles: %v\n", *maxFiles)
	fmt.Printf("writers: %d\n", *writers)
	fmt.Printf("file size: %d\n", *fileSize)
	fmt.Printf("========================\n")

	wg := &sync.WaitGroup{}
	wg.Add(*writers)

	var (
		errorsCount  int64
		successCount int64
	)

	start := time.Now()

	for range *writers {
		go func() {
			defer wg.Done()

			for ctx.Err() == nil && atomic.LoadInt64(&successCount) < int64(*maxFiles) {
				filename := uuid.NewString()
				if err := os.WriteFile(filename, buffer, 0644); err != nil {
					log.Printf("error writing file %q: %v", filename, err)
					atomic.AddInt64(&errorsCount, 1)
					continue
				}
				atomic.AddInt64(&successCount, 1)
			}
		}()
	}

	wg.Wait()

	elapsed := time.Since(start)
	fmt.Println("\n\n========= RESULTS =========")
	fmt.Printf("files created: %d\n", successCount)
	fmt.Printf("throughput: %f/s\n", float64(successCount)/elapsed.Seconds())
	fmt.Printf("errors: %d\n", errorsCount)
	fmt.Printf("error rate: %d\n", errorsCount/(errorsCount+successCount))
}
