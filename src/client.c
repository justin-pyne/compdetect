#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <errno.h>

#define CONFIG_BUFFER_SIZE 1024
#define RESULT_BUFFER_SIZE 256

typedef struct {
    char server_ip[64];
    int udp_src_port;
    int udp_dst_port;
    int tcp_pre_port;
    int tcp_post_port;
    int payload_size;
    int gamma;
    int num_packets;
} Config;