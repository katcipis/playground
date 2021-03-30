package main

import (
	"github.com/sirupsen/logrus"
)

func main() {
	logrus.SetLevel(logrus.InfoLevel)

	test1 := logrus.New()
	test1.Debug("should not see me")

	logrus.SetLevel(logrus.DebugLevel)

	test2 := logrus.New()
	test1.Debug("should see me 1")
	test2.Debug("should see me 2")
}
