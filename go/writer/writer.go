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
	writers := flag.Int("writers", 1, "how many concurrent writers")

	ctx, cancel1 := context.WithTimeout(context.Background(), *duration)
	defer cancel1()
	ctx, cancel2 := signal.NotifyContext(ctx, os.Interrupt)
	defer cancel2()

	buffer := make([]byte, *fileSize)
	_, _ = rand.Read(buffer)

	fmt.Printf("running writer for %v with %d writers and file size %d\n", *duration, *writers, *fileSize)

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

			for ctx.Err() == nil {
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
	fmt.Printf("files created: %d", successCount)
	fmt.Printf("throughput: %d/s", float64(successCount)/elapsed.Seconds())
	fmt.Printf("errors: %d", errorsCount)
	fmt.Printf("error rate: %d", errorsCount/(errorsCount+successCount))
}
