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
#include "common.h"
int xconnect(char* ip, char* port)
{
  char temp[100]="connecting to ";
  // socket descriptor begins here
  int sockfd;
  struct sockaddr_in servaddr;
  sockfd = Socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(port));
  
  Inet_pton(AF_INET, ip, &servaddr.sin_addr);
  // socket descriptor ends here
  strcat(temp,ip);
  Fputs(temp, stdout);
  Fputs("\n",stdout);
  Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  //connect to the server
  return sockfd;
}
