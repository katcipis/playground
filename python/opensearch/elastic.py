import os
from elasticsearch import Elasticsearch

client = Elasticsearch(
    hosts="https://" + os.getenv("ELASTICSEARCH_IP") + ":" + os.getenv("ELASTICSEARCH_PORT"),
    basic_auth=(os.getenv("ELASTICSEARCH_USER"), os.getenv("ELASTICSEARCH_PASSWORD")),
)

index_name = 'test-elasticsearch-index'
index_body = {
  'settings': {
    'index': {
      'number_of_shards': 4
    }
  }
}

response = client.indices.create(index=index_name, body=index_body)
print(response)
