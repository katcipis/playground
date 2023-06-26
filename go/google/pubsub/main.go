package main

import (
	"context"
	"fmt"
	"os"
	"time"

	"gocloud.dev/pubsub"
	_ "gocloud.dev/pubsub/gcppubsub"
)

func main() {
	project := os.Getenv("PROJECT")
	topic := os.Getenv("TOPIC")
	ctx, cancel := context.WithTimeout(context.Background(), time.Minute)
	defer cancel()

	t, err := pubsub.OpenTopic(ctx, fmt.Sprintf("gcppubsub://projects/%s/topics/%s", project, topic))
	if err != nil {
		fmt.Println("error opening topic:", err)
		os.Exit(1)
	}
	defer t.Shutdown(ctx)

	err = t.Send(ctx, &pubsub.Message{Body: []byte("Hello, World!\n")})
	if err != nil {
		fmt.Println("error sending message:", err)
		os.Exit(1)
	}
	fmt.Println("success !!!")
}
