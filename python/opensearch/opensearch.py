import os
from opensearchpy import OpenSearch

client = OpenSearch(
    hosts=os.getenv("ELASTICSEARCH_IP"),
    port=os.getenv("ELASTICSEARCH_PORT"),
    http_auth=(os.getenv("ELASTICSEARCH_USER"), os.getenv("ELASTICSEARCH_PASSWORD")),
    timeout=30,
    use_ssl=True,
)

index_name = 'test-opensearch-index'
index_body = {
  'settings': {
    'index': {
      'number_of_shards': 4
    }
  }
}

response = client.indices.create(index_name, body=index_body)
print(response)
