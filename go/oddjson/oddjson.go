package main

import (
	"encoding/json"
	"fmt"
)

func main() {
	data := []byte(`{
		"Type": "hi"
	}`)

	parsed := struct {
		Type string `json:"type"`
	}{}

	parsedmap := map[string]interface{}{}

	fmt.Println(json.Unmarshal(data, &parsed))
	fmt.Println(json.Unmarshal(data, &parsedmap))

	fmt.Printf("parsed: %+v\n", parsed)
	fmt.Printf("parsedmap: %s\n", parsedmap)
}
