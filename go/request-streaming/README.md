# Reproducing

First run:

```sh
go run server.go
```

Then run:

```sh
go run github.com/katcipis/requestbin@master -p 8081
```

Requests will be echoed by the requestbin.
Now just send a request to the server running at 8080:

```sh
curl localhost:8080 -d "some request body"
```
