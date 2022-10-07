package main

import (
	"github.com/rs/zerolog"
	"github.com/rs/zerolog/log"
)

func main() {
	zerolog.SetGlobalLevel(zerolog.Disabled)
	logger := log.With().Logger()
	logger.Fatal().Msg("fatal msg")
}
