DEV=docker run --rm -ti -v `pwd`:/app -w /app clojure
LEIN=$(DEV) lein

run: 
	$(LEIN) run

shell:
	$(DEV) bash

new-app:
	$(LEIN) new app $(name)

stop-pg:
	docker stop test-pg
	docker rm test-pg

start-pg:
	docker run --name="test-pg" --net="host" -d postgres:9.2
