package main

import (
	"context"
	"fmt"
	"log"
	"time"

	"golang.org/x/oauth2/google"
)

func main() {
	params := google.CredentialsParams{
		Scopes: []string{
			"https://www.googleapis.com/auth/cloud-platform",
			"https://www.googleapis.com/auth/cloud-platform.read-only",
		},
		EarlyTokenRefresh: 5 * time.Minute,
	}
	creds, err := google.FindDefaultCredentialsWithParams(context.Background(), params)
	if err != nil {
		log.Fatalf("No 'Application Default Credentials' found: %v.", err)
	}

	fmt.Println("Found creds: ", creds)

	token1, err := creds.TokenSource.Token()
	if err != nil {
		log.Fatalf("Failed to generate token 1: %v.", err)
	}
	token2, err := creds.TokenSource.Token()
	if err != nil {
		log.Fatalf("Failed to generate token 2: %v.", err)
	}

	fmt.Println("Generated token1: ", token1)
	fmt.Println("Generated token2: ", token2)
}
