#include "common.h"
#define BUFSIZE 1000

void echo_client(int sockfd)
{	
	char buf[BUFSIZE];
	bzero(buf, BUFSIZE);
	if(read(sockfd, buf, BUFSIZE)<0)
		err_sys("server read error");
	printf("debug read: %s\n", buf);
} 
