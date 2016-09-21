import json

a = b'"{\\"id\\": 1}"'
b = json.loads(a.decode("utf-8"))

print("\n\nParsed JSON: \n\n")

print(b, type(b))

print("\n\nHow parsing a JSON can return ONE string ?")
print(
    """
    http://www.json.org/

    JSON is built on two structures:

    A collection of name/value pairs. In various languages, this is realized as an object, record, struct, dictionary, hash table, keyed list, or associative array.
    An ordered list of values. In most languages, this is realized as an array, vector, list, or sequence.
    """
)

print("Expected at least an error, Bad Python :-)\n\n")
