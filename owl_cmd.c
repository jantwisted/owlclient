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

void xcommand(char** str, int *sockfd){
  char spacer[2]=" ";
  char* cmd;
  char* option;
  char* other;
  
  /* prepare parameters for xrun() */
  cmd = strtok(str, spacer);
  option = strtok(NULL, spacer);
  option = (option==NULL)?"default":option;
  other = strtok(NULL, spacer);
  other = (other==NULL)?"default":other;
  /*call xrun()*/
  xrun(cmd, option, other, sockfd);
}
