# Google Cloud PubSub

First run the emulator:

```sh
docker run --rm --network host gcr.io/google.com/cloudsdktool/google-cloud-cli:emulators gcloud beta emulators pubsub start --project=jojo
```

Then export this env var before running any other code:

```sh
export PUBSUB_EMULATOR_HOST=localhost:8085
```

Then create the topic and subscription:

```sh
python setup.py
```

Then publish some messages:

```sh
python publisher.py
```

Then receive some messages: 

```sh
python subscriber.py
```
