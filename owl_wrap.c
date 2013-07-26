/* 
   <OwlClient is a simple program which can send and receive messages from a server. This is specially designed to xml and json.>
   Copyright (C) <2013>  <Janith Perera>

   This file is part of OwlClient.

   OwlClient is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   OwlClient is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with OwlClient.  If not, see <http://www.gnu.org/licenses/>.
*/
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


