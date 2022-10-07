package main

import (
	"fmt"

	"github.com/rs/zerolog"
	"github.com/rs/zerolog/log"
)

func main() {
	zerolog.SetGlobalLevel(zerolog.Disabled)
	logger := log.With().Logger()
	fmt.Println("before fatal")
	logger.Fatal().Msg("fatal msg")
	fmt.Println("after fatal")
}
