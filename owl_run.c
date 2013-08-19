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

   Note: All commands should be defined here
*/
#include "common.h"

void xrun(char** cmd, char** opt, char** other, int *sockfd)
{
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
  }else if((strcasecmp(cmd, "SENDR")==0)||(strcasecmp(cmd, "SENDR\n")==0)){
    xwrite(*sockfd, xfile_read());
    xread(*sockfd);
  }else if((strcasecmp(cmd, "DEFAULT")==0)||(strcasecmp(cmd, "DEFAULT\n")==0)){
    FILE *file;
    file = fopen("config.ini","r+");
    char* param1 = conf_read(file, "SERVER_IP");
    char* param2 = conf_read(file, "SERVER_PORT");
    fputs(param1,stdout);
    fputs(param2,stdout);
    fputs("\n",stdout);
    if((strcasecmp(opt, "CONNECT")==0)||(strcasecmp(opt, "CONNECT\n")==0))
      *sockfd = xconnect(get_value(param1),get_value(param2));
  }else
    Fputs("~uknown command, type 'help' for more information.\n",stdout);
}
