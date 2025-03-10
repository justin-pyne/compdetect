#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
    int udp_dst_port;    // 8765
    int tcp_pre_port;    // 7777
    int tcp_post_port;   // 6666
    int payload_size;
    int gamma;
    int num_packets;
} Config;