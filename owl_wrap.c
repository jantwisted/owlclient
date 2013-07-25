/*
	All the socket functions placed here
*/
#include"common.h"

void Connect(int sockfd, const struct sockaddr *sa, socklen_t socklen)
{
	if(connect(sockfd, sa, socklen)<0)
		err_sys("connect error");
}

int Socket(int family, int type, int protocol)
{
	int n;
	if((n=socket(family, type, protocol))<0)
		err_sys("socket error");
	return n;
}

void Inet_pton(int family, const char *strptr, void *addrptr)
{
        int             n;

        if ( (n = inet_pton(family, strptr, addrptr)) < 0)
                err_sys("inet_pton error for %s", strptr);      
        else if (n == 0)
                err_quit("inet_pton error for %s", strptr);    

      
}


