#include "common.h"
#define BUFSIZE 1000

void xread(int sockfd)
{
  char buf[BUFSIZE];
  bzero(buf, BUFSIZE);
  if(read(sockfd, buf, BUFSIZE)<0)
    err_sys("server read error");
  Fputs(buf,stdout);
}
