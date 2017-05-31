import json

jsondata = open("odd.json", "r").read()

print("decoding: {}\n\n", jsondata)

parsed = json.loads(jsondata)
print("json field: {}\n\n", parsed["json"])

parsedjson = json.loads(parsed["json"])
print("parsed json field: {}\n\n", parsedjson)
