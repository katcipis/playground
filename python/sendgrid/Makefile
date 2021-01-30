all: dev

image:
	docker build . -t sendgrid

dev: image
	docker run -v `pwd`:/app -w /app --rm -ti sendgrid
