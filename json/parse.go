package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
)

func panicerr(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	file, err := os.Open("odd.json")
	panicerr(err)

	jsondata, err := ioutil.ReadAll(file)
	panicerr(file.Close())
	panicerr(err)

	fmt.Printf("decoding: %q\n\n", jsondata)
	parsed := map[string]interface{}{}
	err = json.Unmarshal([]byte(jsondata), &parsed)
	panicerr(err)

	fmt.Printf("json field: %q\n\n", parsed["json"])

	parsedjson := map[string]interface{}{}
	err = json.Unmarshal([]byte(parsed["json"].(string)), &parsedjson)
	panicerr(err)

	fmt.Printf("parsed json field: %q\n\n", parsedjson)
}
