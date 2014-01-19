#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

static struct addrinfo * get_address_info(const gchar * node_address)
{
    int status;
    struct addrinfo hints;
    struct addrinfo *res = {0};  // will point to the results

    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

    status = getaddrinfo(node_address, "3490", &hints, &res);
    return res;
}

int main (int argc, char ** argv)
{
    struct addrinfo * res = get_address_info(argv[1]);
    return EXIT_SUCCESS;
}
