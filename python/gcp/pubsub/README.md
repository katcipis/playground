# Google Cloud PubSub

First run the emulator:

```sh
docker run --rm -p 8085:8085 gcr.io/google.com/cloudsdktool/google-cloud-cli:emulators gcloud beta emulators pubsub start --host-port=0.0.0.0:8085 --project=jojo
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
