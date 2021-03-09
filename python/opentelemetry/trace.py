import time
import jaeger_client

tracer = jaeger_client.Config(
    config={
        "sampler": {"type": "const", "param": 1},
        "local_agent": {
            "reporting_port": 14268,
            "reporting_host": "localhost",
        },
        "logging": True,
    },
    service_name="katcipis-python-test",
    validate=True,
).initialize_tracer()

with tracer.start_span('KatcipisTestSpan') as span:
    span.log_kv({'event': 'test message', 'life': 35})

time.sleep(2)   # yield to IOLoop to flush the spans - https://github.com/jaegertracing/jaeger-client-python/issues/50
tracer.close()  # flush any buffered spans
