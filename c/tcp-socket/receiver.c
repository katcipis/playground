#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

static struct addrinfo * get_address_info (void)
{
    int status;
    struct addrinfo hints = {0};
    struct addrinfo *res;  // will point to the results

    hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me.

    if ((status = getaddrinfo(NULL, "3490", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
        return NULL;
    }
    return res;
}

int main (int argc, char ** argv)
{
    struct addrinfo * res = get_address_info();
    int socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    return EXIT_SUCCESS;
}
