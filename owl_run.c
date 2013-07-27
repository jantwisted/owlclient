/* 
   <OwlClient is a simple program which can send and receive messages from a server. This is specially designed to xml and json.>
   Copyright (C) <2013>  <Janith Perera>

   This file is part of OwlClient.

   OwlClient is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Foobar is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with OwlClient.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "common.h"

void xrun(char** cmd, char** opt, char** other, int *sockfd)
{
  //int sockfd;
  if((strcasecmp(cmd, "CONNECT")==0)||(strcasecmp(cmd, "CONNECT\n")==0)){
    *sockfd = xconnect(opt, other);
  }else if((strcasecmp(cmd, "CONNECTR")==0)||(strcasecmp(cmd, "CONNECTR\n")==0)){
    *sockfd = xconnect(opt, other);
    xread(*sockfd);
  }else if(strcasecmp(cmd, "HELP\n")==0){
    xhelp();
  }else if((strcasecmp(cmd, "WRITE")==0)||(strcasecmp(cmd, "WRITE\n")==0)){
    xwrite(*sockfd, "example message\n");
  }else if((strcasecmp(cmd, "SEND")==0)||(strcasecmp(cmd, "SEND\n")==0)){
    xwrite(*sockfd, xfile_read());
  }else
    Fputs("~uknown command, type 'help' for more information.\n",stdout);
}
