package main

import "fmt"

func overall(samples []float64) float64 {
	var total float64
	for _, sample := range samples {
		total += sample
	}
	return total / float64(len(samples))
}

func symmetric2avgs(samples []float64) float64 {
	half := len(samples) / 2
	samples1 := samples[0:half]
	samples2 := samples[half:]
	fmt.Println("symmetric2avgs: ", samples1, samples2)
	return (overall(samples1) + overall(samples2)) / 2
}

func asymmetric2avgs(samples []float64) float64 {
	// Depending on the len this will break, test only ;-)
	nothalf := (len(samples) / 2) - 3
	samples1 := samples[0:nothalf]
	samples2 := samples[nothalf:]
	fmt.Println("asymmetric2avgs: ", samples1, samples2)
	return (overall(samples1) + overall(samples2)) / 2
}

func main() {
	samples := []float64{
		2,
		4,
		10,
		14,
		8,
		6,
		100,
		50,
		30,
		10,
		4,
		12,
	}
	fmt.Println("samples:", samples)
	fmt.Println("overall avg:", overall(samples))
	fmt.Println("symmetric two avgs:", symmetric2avgs(samples))
	fmt.Println("asymmetric two avgs:", asymmetric2avgs(samples))
}
