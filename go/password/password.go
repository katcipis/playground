package main

import (
	"fmt"

	"golang.org/x/crypto/bcrypt"
)

func main() {
	password := []byte("badpassword")

	hashed, err := bcrypt.GenerateFromPassword(password, bcrypt.DefaultCost)
	if err != nil {
		panic(err)
	}

	fmt.Println(string(hashed))
	fmt.Println(bcrypt.CompareHashAndPassword(hashed, password))
	fmt.Println(bcrypt.CompareHashAndPassword(hashed, password[1:]))
}
