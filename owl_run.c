#include "common.h"

void xrun(char** cmd, char** opt, char** other)
{
  int sockfd;
  if((strcasecmp(cmd, "CONNECT")==0)||(strcasecmp(cmd, "CONNECT\n")==0)){
    /*    Fputs("CONNECTED\n", stdout);
	  Fputs(opt,stdout);
	  Fputs(other,stdout);
	  Fputs("\n",stdout); */
    sockfd = xconnect(opt, other);
    xread(sockfd);
  }else
    Fputs("~uknown command\n",stdout);
}
