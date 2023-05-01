import os
import json
import requests

API_TOKEN=os.getenv("API_TOKEN")
API_URL = "https://api-inference.huggingface.co/models/facebook/opt-iml-max-1.3b"
headers = {"Authorization": f"Bearer {API_TOKEN}"}

def query(payload):
    data = json.dumps(payload)
    response = requests.request("POST", API_URL, headers=headers, data=data)
    return json.loads(response.content.decode("utf-8"))

data = query("I don't know")

print("results:")
print(data)
