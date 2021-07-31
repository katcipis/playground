package benchmarks

func Mem(count int) {
	var x []byte
	for i := 0; i < count; i++ {
		x = make([]byte, 1024)
		for i := range x {
			x[i] = 6
		}
	}
}
