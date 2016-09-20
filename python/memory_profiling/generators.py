from memory_profiler import profile

@profile
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

@profile
def iterate_with_generator(size):
    iterate_the_iterator(generator_iterator(size), size)

@profile
def iterate_with_list(size):
    iterate_the_iterator(list_iterator(size), size)


@profile
def run(size):
    iterate_with_generator(size)
    iterate_with_list(size)
    iterate_with_generator(size)
    iterate_with_list(size)

run(100000)
