package main

import (
	"log"
	"time"
)

func main() {
	const days = 10_000
	start := parseTime("2024-02-06T00:00:00Z")

	for i := 0; i < days; i++ {
		next := start.Add(24 * time.Hour)
		if (next.Month() == start.Month()) && (next.Day()-start.Day()) != 1 {
			log.Fatalf("day smaller than 24 hours: start %v; next %v", start, next)
		}
		start = next
	}
}

func parseTime(s string) time.Time {
	v, err := time.Parse(time.RFC3339, s)
	if err != nil {
		panic(err)
	}
	return v
}
