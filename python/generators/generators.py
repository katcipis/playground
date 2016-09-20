def iterate_the_iterator(iterator, size):
    i = 0
    for x in iterator:
        i += x["a"]
    assert i == size


@profile
def generator_iterator(size):
    i = 0
    while i < size:
        yield {"a": 1}
        i += 1

@profile
def list_iterator(size):
    return [{"a": 1} for x in range(size)]

print("starting all the fun")
SIZE = 100000

@profile
def iterate_with_generator():
    iterate_the_iterator(generator_iterator(SIZE), SIZE)

@profile
def iterate_with_list():
    iterate_the_iterator(list_iterator(SIZE), SIZE)

iterate_with_generator()
iterate_with_list()
