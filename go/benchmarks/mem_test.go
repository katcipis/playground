package benchmarks_test

import (
	"fmt"
	"testing"

	"github.com/katcipis/playground/go/benchmarks"
)

func BenchmarkMem(b *testing.B) {
	allocCounts := []int{10, 100, 1000, 10000}
	for _, allocCount := range allocCounts {
		b.Run(fmt.Sprintf("AllocCount%d", allocCount), func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				benchmarks.Mem(allocCount)
			}
		})
	}
}
