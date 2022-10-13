package main

import (
	"fmt"

	"github.com/rs/zerolog"
	"github.com/rs/zerolog/log"
)

func main() {
	zerolog.SetGlobalLevel(zerolog.WarnLevel)
	logger := log.With().Logger()
	fmt.Println("before fatal")
	logger.WithLevel(zerolog.FatalLevel).Msg("fatal msg")
	fmt.Println("after fatal")
}
