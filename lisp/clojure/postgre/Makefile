DEV=docker run --rm -ti -v `pwd`:/app -w /app clojure
LEIN=$(DEV) lein

run: 
	$(LEIN) run

shell:
	$(DEV) bash

new-app:
	$(LEIN) new app $(name)
