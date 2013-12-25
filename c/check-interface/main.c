#include <stdio.h>
#include <stdlib.h>

#define assert(should_be_1, ...) \
        if (!should_be_1) {      \
            printf(__VA_ARGS__);    \
            exit(EXIT_FAILURE);                \
        }

struct interface_s {
    void (*a_function)(void);
    void (*another_function)(void);
};

/* we have to use packed to force the struct to not be aligned on 32 or 64 bits boundaries */
struct __attribute__((__packed__)) invalid_interface_s {
    void (*a_function)(void);
    void (*another_function)(void);
    char should_not_be_here;
};

int validate_interface(void * interface, size_t interface_size)
{
    if (interface == 0) return 0;
    if (interface_size % sizeof(void*) != 0) {
        printf("interface size is not multiple from pointer size, it should only have pointers inside !!!\n");
        return 0;
    }
    void * interface_end = interface + interface_size;
    while (interface < interface_end) {
        void ** function_pointer = (void**)interface;
        if (*function_pointer == 0) return 0;
        interface += sizeof(void*);
    }
    return 1;
}

static inline int 
myinterface_is_valid(struct interface_s *self)
{
    return validate_interface(self, sizeof(struct interface_s));
}

static void a_valid_function()
{
}

int main()
{
    struct interface_s *interface_null = NULL;
    struct interface_s *interface_empty = &(struct interface_s) { 0 };
    struct interface_s *interface_incomplete = &(struct interface_s) {
        .a_function = a_valid_function,
        .another_function = 0
    };
    struct interface_s *interface_ok = &(struct interface_s) {
        .a_function = a_valid_function,
        .another_function = a_valid_function
    };
    struct invalid_interface_s *interface_invalid = &(struct invalid_interface_s) {
        .a_function = a_valid_function,
        .another_function = a_valid_function,
        .should_not_be_here = '1'
    };

    assert(myinterface_is_valid(interface_null) == 0, "Fail interface_null \n");
    assert(myinterface_is_valid(interface_empty) == 0, "Fail interface_empty \n");
    assert(myinterface_is_valid(interface_incomplete) == 0, "Fail interface_incomplete \n");
    assert(validate_interface(interface_invalid, sizeof(struct invalid_interface_s)) == 0, "Fail interface_invalid\n");
    assert(myinterface_is_valid(interface_ok) == 1, "Fail interface_ok \n");

    return EXIT_SUCCESS;
}
